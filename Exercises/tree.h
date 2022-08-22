#include <fstream>
#include <functional>
#include <iostream>
#include <memory>

namespace dz {
    // exceptions.hpp

    /// \brief Thrown when trying to access empty container.
    struct EmptyContainer : public std::exception {
        const char *what() const throw() { return "container is empty"; }
    };

    /// \brief Throws when trying to access an element that doesn't exist.
    struct OutOfRange : public std::exception {
        const char *what() const throw() { return "index out of range"; }
    };

    // sfinae.hpp

    namespace detail {

        template <typename T, typename U> struct has_operator_greater_impl {
            template <typename T_ = T, typename U_ = U> // template parameters here to enable SFINAE
            static auto test(T_ &&t, U_ &&u) -> decltype(t > u, std::false_type{}, std::true_type{});
            static auto test(...) -> std::false_type;
            using type = decltype(test(std::declval<T>(), std::declval<U>()));
        };

        template <typename T, typename U> struct has_operator_equals_impl {
            template <typename T_ = T, typename U_ = U> // template parameters here to enable SFINAE
            static auto test(T_ &&t, U_ &&u) -> decltype(t == u, std::false_type{}, std::true_type{});
            static auto test(...) -> std::false_type;
            using type = decltype(test(std::declval<T>(), std::declval<U>()));
        };

        template <typename T> struct has_operator_ostream_impl {
            template <typename T_ = T> // template parameters here to enable SFINAE
            static auto test(std::ostream &&os, T_ &&t) -> decltype(os << t, std::false_type{}, std::true_type{});
            static auto test(...) -> std::false_type;
            using type = decltype(test(std::declval<std::ostream>(), std::declval<T>()));
        };

    } // namespace detail

    template <typename T, typename U = T>
    struct has_operator_greater : detail::has_operator_greater_impl<T, U>::type {};

    template <typename T, typename U = T>
    struct has_operator_equals : detail::has_operator_equals_impl<T, U>::type {};

    template <typename T>
    struct has_operator_ostream : detail::has_operator_ostream_impl<T>::type {};

    // container.hpp

    namespace detail {

        template <typename T> struct Node {
            std::shared_ptr<Node<T>> next;
            T value;

            explicit Node(T value_, std::shared_ptr<Node<T>> next_)
                    : next{next_}, value{value_} {}

            explicit Node(std::shared_ptr<Node<T>> other)
                    : next{other->next}, value{other->value} {}
        };

        /// \brief Base Container Class
        template <typename T> class Container {
        public:
            using node_type = Node<T>;
            using node_wrap = std::shared_ptr<Node<T>>;
            using size_type = unsigned long int;

            int npos = -1;

        protected:
            node_wrap head;
            node_wrap tail;
            size_type count;

            _Pragma("GCC diagnostic push")
            _Pragma("GCC diagnostic ignored \"-Wreturn-type\"")
            _Pragma("GCC diagnostic ignored \"-Wunused-parameter\"")

            virtual auto _pop() -> T = 0;
            virtual auto _pop(int pos) -> T {}
            virtual auto _push(const T &val) -> void = 0;
            virtual auto _deepcopy(node_wrap n) -> void = 0;

            _Pragma("GCC diagnostic pop")

            auto deepcopy(node_wrap n) -> void {
                _deepcopy(n);
            }

        public:
            class Iterator;

            auto begin() -> Iterator { return Iterator{head}; }
            auto end() -> Iterator { return Iterator{nullptr}; }

            Container() : head{nullptr}, tail{nullptr}, count{0} {}

            Container(const Container &other) : count{0} { deepcopy(other.head); }

            /// \brief Push an element into the container.
            auto push(const T &val) -> void {
                _push(val);
                count++;
            }

            /// \brief Push any amount of elements into the container.
            template <typename... Args>
            auto push(const T &val, const Args &...args) -> void {
                push(val);
                push(args...);
            }

            /// \brief Remove an element from the container.
            auto pop() -> T {
                T tmp{_pop()};
                count--;
                return tmp;
            }

            /// \brief Remove an element at position pos from the container.
            auto pop(size_type pos) -> T {
                if (pos >= size()) {
                    throw OutOfRange{};
                }
                T tmp{_pop(pos)};
                count--;
                return tmp;
            }

            auto empty() const -> bool { return count == 0; }

            auto size() const -> size_type { return count; }

            /// \brief Load container from file.
            template <typename T_ = T,
                    typename std::enable_if<std::is_arithmetic<T_>::value, T_>::type* = nullptr>
            auto load(const std::string &filepath) -> void {
                std::string s;
                std::ifstream f;
                f.open(filepath);
                while (std::getline(f, s)) {
                    push(std::stoi(s));
                }
            }

            /// \brief Load container from file.
            template <typename T_ = T,
                    typename std::enable_if<std::is_same<T_, std::string>::value, T_>::type* = nullptr>
            auto load(const std::string &filepath) -> void {
                std::string s;
                std::ifstream f;
                f.open(filepath);
                while (std::getline(f, s)) {
                    push(s);
                }
            }

            /// \brief Load container from file.
            auto load(const std::string &filepath,
                      const std::function<T(const std::string &)> &callback) -> void {
                std::string s;
                std::ifstream f;
                f.open(filepath);
                while (std::getline(f, s)) {
                    push(callback(s));
                }
            }

            /// \brief Save container to file.
            auto save(const std::string &filepath) const
            -> decltype(has_operator_ostream<T>::value, void()) {
                std::ofstream f;
                f.open(filepath);
                map([&f](const T &i) { f << i << '\n'; });
                f.close();
            }

            /// \brief Save container to file.
            auto save(const std::string &filepath,
                      const std::function<std::string(const T &)> &callback) const
            -> void {
                std::ofstream f;
                f.open(filepath);
                map([&f, &callback](const T &i) { f << callback(i) << '\n'; });
                f.close();
            }

            /// \brief Streams container nodes to ostream.
            auto stream(std::ostream &os, const std::string &delim = " ") const
            -> decltype(has_operator_ostream<T>::value, void()) {
                auto i = head.get();
                for (; i->next.get(); i = i->next.get()) {
                    os << i->value << delim;
                }
                os << i->value;
            }

            /// \brief Streams container nodes to ostream.
            auto stream(std::ostream &os, const std::string &delim,
                        const std::function<std::string(T &)> &f) const
            -> decltype(has_operator_ostream<T>::value, void()) {
                auto i = head.get();
                for (; i->next.get(); i = i->next.get()) {
                    os << f(i->value) << delim;
                }
                os << f(i->value);
            }

            /// \brief Streams container nodes to sstream.
            auto stream(std::stringstream &ss, const std::string &delim) const
            -> decltype(has_operator_ostream<T>::value, void()) {
                auto i = head.get();
                for (; i->next.get(); i = i->next.get()) {
                    ss << i->value << delim;
                }
                ss << i->value;
            }

            /// \brief Print container to stdout.
            auto print() const -> void {
                std::cout << "[";
                stream(std::cout, ", ");
                std::cout << "]\n";
            }

            /// \brief Print container to stdout.
            auto print(const std::function<std::string(T &)> &f) const -> void {
                std::cout << "[";
                stream(std::cout, ", ", f);
                std::cout << "]\n";
            }

            /// \brief Map function to container.
            auto map(const std::function<void(T &)> &f) -> void {
                for (auto i = head.get(); i; i = i->next.get()) {
                    f(i->value);
                }
            }

            /// \brief Map function to container.
            auto map(const std::function<void(const T &)> &f) const -> void {
                for (auto i = head.get(); i; i = i->next.get()) {
                    f(i->value);
                }
            }

            auto find(const std::function<bool(const T &)> &f) const -> int {
                int index = 0;
                for (auto i = head.get(); i; i = i->next.get()) {
                    if (f(i->value)) {
                        return index;
                    }
                    index++;
                }
                return npos;
            }
        };

        template <typename T> class Container<T>::Iterator {
        public:
            node_wrap n;
            explicit Iterator(node_wrap n_) : n{n_} {}
            auto operator++() -> void { n = n->next; }
            auto operator!=(Iterator rhs) const -> bool { return n.get() != rhs.n.get(); }
            auto operator*() -> T & { return n->value; }
        };
    } // namespace detail

    // stack.hpp

    template <typename T> class Stack final : public detail::Container<T> {
    public:
        using node_type = typename detail::Container<T>::node_type;
        using node_wrap = typename detail::Container<T>::node_wrap;

    protected:
        using detail::Container<T>::count;
        using detail::Container<T>::head;

        auto _deepcopy(node_wrap n) -> void override {
            if (n) {
                _deepcopy(n->next);
                push(n->value);
            }
        }

        auto _push(const T &val) -> void override {
            head = std::make_shared<node_type>(val, head);
        }

        auto _pop() -> T override {
            if (empty()) {
                throw EmptyContainer{};
            }
            auto tmp = head;
            auto v = tmp->value;
            head = head->next;
            return v;
        }

    public:
        using detail::Container<T>::Container;
        using detail::Container<T>::empty;
        using detail::Container<T>::pop;
        using detail::Container<T>::push;

        auto pop(int pos) -> T = delete;

        auto top() -> T {
            if (empty()) {
                throw EmptyContainer{};
            }
            return head->value;
        }
    };

    // tree.hpp

    namespace detail {
        template <typename T> struct BNode {
            std::shared_ptr<BNode<T>> sx;
            std::shared_ptr<BNode<T>> dx;
            T value;

            BNode(T value_, std::shared_ptr<BNode<T>> sx_, std::shared_ptr<BNode<T>> dx_)
                    : sx{sx_}, dx{dx_}, value{value_} {}
        };

    } // namespace detail

    enum class DisplayMethod { PreOrder, PostOrder, InOrder };

    template <typename T> class BST {
        using size_type = unsigned long int;

        using node_type = detail::BNode<T>;
        using node_wrap = std::shared_ptr<detail::BNode<T>>;

    private:
        node_wrap head;
        size_type count;

        void stream_preorder(std::ostream &os,
                             node_wrap n,
                             const std::string &delim,
                             size_type &nth) const {
            nth += 1;
            os << n->value << (nth < size() ? delim : "");
            if (n->sx) stream_preorder(os, n->sx, delim, nth);
            if (n->dx) stream_preorder(os, n->dx, delim, nth);
        }

        void stream_postorder(std::ostream &os,
                              node_wrap n,
                              const std::string &delim,
                              size_type &nth) const {
            if (n->sx) stream_postorder(os, n->sx, delim, nth);
            if (n->dx) stream_postorder(os, n->dx, delim, nth);
            nth += 1;
            os << n->value << (nth < size() ? delim : "");
        }

        void stream_inorder(std::ostream &os,
                            node_wrap n,
                            const std::string &delim,
                            size_type &nth) const {
            if (n->sx) stream_inorder(os, n->sx, delim, nth);
            nth += 1;
            os << n->value << (nth < size() ? delim : "");
            if (n->dx) stream_inorder(os, n->dx, delim, nth);
        }

        /// \brief Remove node with element i in tree.
        node_type *erase(node_type *n, T val) {
            if (n == nullptr) {
                return n;
            } else if (val < n->value) {
                n->sx = erase(n->sx, val);
            } else if (val > n->value) {
                n->dx = erase(n->dx, val);
            } else {
                if (n->sx == nullptr) {
                    return n->dx;
                } else if (n->dx == nullptr) {
                    return n->sx;
                } else {
                    n->value = n->sx->value;
                    n->sx = erase(n->sx, n->value);
                }
            }
            return n;
        }

    public:
        class Iterator;

        Iterator begin() const { return Iterator{head}; }
        Iterator end() const { return Iterator{head}; }

        BST() : head{nullptr}, count{0} {}

        /// \brief Push an element into the tree.
        void push(const T &val) {
            if (head == nullptr) {
                head = std::make_shared<node_type>(val, nullptr, nullptr);
                count++;
                return;
            }

            auto n = &head;
            while (*n != nullptr) {
                if (val < (*n)->value) {
                    n = &(*n)->sx;
                } else if (val > (*n)->value) {
                    n = &(*n)->dx;
                } else {
                    break;
                }
            }
            *n = std::make_shared<node_type>(val, nullptr, nullptr);
            count++;
        }

        /// \brief Push any amount of elements into the tree.
        template <typename... Args> void push(T val, const Args &...args) {
            push(val);
            push(args...);
        }

        /// \brief Returns the root of the tree.
        T top() const { return head->value; }

        /// \brief Removes and returns the root of the tree.
        T pop() { return erase(head, top())->value; }

        /// \brief Erases the element in the tree with value i.
        void erase(const T &val) { erase(head, val); }

        /// \brief Erases as many element in the tree with values...
        template <typename... Args> void erase(const T &val, const Args &...args) {
            erase(val);
            erase(args...);
        }

        bool empty() const { return !(head->sx && head->dx); }

        size_type size() const { return count; }

        /// \brief Stream tree to ostream
        auto stream(std::ostream &os,
                    const std::string &delim = " ",
                    DisplayMethod method = DisplayMethod::PreOrder) const
        -> decltype(has_operator_ostream<T>::value) {
            size_type nth = 0;
            if (head) {
                switch (method) {
                    case DisplayMethod::PreOrder:
                        stream_preorder(os, head, delim, nth);
                        break;
                    case DisplayMethod::PostOrder:
                        stream_postorder(os, head, delim, nth);
                        break;
                    case DisplayMethod::InOrder:
                        stream_inorder(os, head, delim, nth);
                        break;
                }
            }
        }

        void print(DisplayMethod method = DisplayMethod::InOrder) const {
            std::cout << "[";
            stream(std::cout, ", ", method);
            std::cout << "]\n";
        }

        /// Caution, must rebuild the tree if values in it are modified.
        void map(const std::function<void(T &)> &f) {
            for (auto &i : *this) {
                f(i);
            }
        }

        void map(const std::function<void(const T &)> &f) const {
            for (const auto &i : *this) {
                f(i);
            }
        }

        void rebuild() {
            BST<T> t{};
            for (const auto &i : *this) {
                t.push(i);
            }
            *this = t;
        }
    };

    /// TODO implement for different visit methods
    template <typename T> class BST<T>::Iterator {
    private:
        node_wrap n;
        T *value;
        bool done;

        Stack<node_wrap> stack;

        void push_left(node_wrap node) {
            while (node.get() != nullptr) {
                stack.push(node);
                node = node->sx;
            }
        }

    public:
        Iterator(node_wrap n_) : n{n_}, value{&n_->value}, done{false}, stack{} {
            push_left(n_);
            ++*this;
        }

        bool operator!=([[maybe_unused]] Iterator) const { return !done; }
        T &operator*() { return *value; }

        void operator++() {
            if (!stack.size()) {
                done = true;
                return;
            }
            auto top = stack.pop();
            if (top->dx.get()) {
                push_left(top->dx);
            }
            value = &top->value;
        }
    };

} // namespace dz

int main() {
    dz::BST<int> s;
    s.push(3, 1, 2, 4, 7, 5, 9, 6, 8, 0);
    s.print();
}
