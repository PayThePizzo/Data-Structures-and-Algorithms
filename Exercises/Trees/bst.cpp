//
// Created by PayThePizzo on 3/15/2022.
//

#ifndef TREE_HPP_
#define TREE_HPP_

#include <functional>
#include <fstream>
#include <iostream>
#include <memory>

#include "stack.hpp"

namespace dz
{

    namespace detail
    {

        template <typename T>
        struct BNode
        {
            std::shared_ptr<BNode<T>> sx;
            std::shared_ptr<BNode<T>> dx;
            T value;

            BNode(T value_, std::shared_ptr<BNode<T>> sx_, std::shared_ptr<BNode<T>> dx_)
                    : sx{sx_}
                    , dx{dx_}
                    , value{value_} {}
        };

    } // namespace detail

    enum class DisplayMethod { PreOrder, PostOrder, InOrder };

    template <typename T>
    class BST
    {
        using size_type = unsigned long int;

        using node_type = detail::BNode<T>;
        using node_wrap = std::shared_ptr<detail::BNode<T>>;

    private:
        node_wrap head;
        size_type count;

        void stream_preorder(std::ostream &os, node_wrap n, const std::string &delim, size_type &nth) const
        {
            nth += 1;
            os << n->value << (nth < size() ? delim : "");
            if (n->sx) stream_preorder(os, n->sx, delim, nth);
            if (n->dx) stream_preorder(os, n->dx, delim, nth);
        }

        void stream_postorder(std::ostream &os, node_wrap n, const std::string &delim, size_type &nth) const
        {
            nth += 1;
            if (n->sx) stream_postorder(os, n->sx, delim, nth);
            if (n->dx) stream_postorder(os, n->dx, delim, nth);
            os << n->value << (nth < size() ? delim : "");
        }

        void stream_inorder(std::ostream &os, node_wrap n, const std::string &delim, size_type &nth) const
        {
            nth += 1;
            if (n->sx) stream_inorder(os, n->sx, delim, nth);
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

        Iterator begin() const
        {
            return Iterator{head};
        }

        Iterator end() const
        {
            return Iterator{head};
        }

        BST()
                : head{nullptr}
                , count{0} {}

        /// \brief Push an element into the tree.
        void push(const T &val)
        {
            if (head == nullptr) {
                head = std::make_shared<node_type>(val, nullptr, nullptr);
                count++;
                return;
            }

            auto n = &head;
            while (*n != nullptr) {
                if (val < (*n)->value)
                    n = &(*n)->sx;
                else if (val > (*n)->value)
                    n = &(*n)->dx;
                else break;
            }
            *n = std::make_shared<node_type>(val, nullptr, nullptr);
            count++;
        }

        /// \brief Push any amount of elements into the tree.
        template <typename ... Args>
        void push(T val, const Args& ... args)
        {
            push(val);
            push(args...);
        }

        /// \brief Returns the root of the tree.
        T top() const
        {
            return head->value;
        }

        /// \brief Removes and returns the root of the tree.
        T pop()
        {
            return erase(head, top())->value;
        }

        /// \brief Erases the element in the tree with value i.
        void erase(const T &val)
        {
            erase(head, val);
        }

        /// \brief Erases as many element in the tree with values...
        template <typename ... Args>
        void erase(const T &val, const Args& ... args)
        {
            erase(val);
            erase(args...);
        }

        bool empty() const
        {
            return !(head->sx && head->dx);
        }

        size_type size() const
        {
            return count;
        }

        /// \brief Stream tree to ostream
        auto stream(std::ostream &os, const std::string &delim = " ", DisplayMethod method = DisplayMethod::PreOrder) const
        -> decltype(has_operator_ostream<T>::value)
                {
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

        void print(DisplayMethod method = DisplayMethod::InOrder) const
        {
            std::cout << "[";
            stream(std::cout, ", ", method);
            std::cout << "]\n";
        }

        /// Caution, must rebuild the tree if values in it are modified.
        void map(const std::function<void(T&)> &f)
        {
            for (auto &i : *this)
                f(i);
        }

        void map(const std::function<void(const T&)> &f) const
        {
            for (const auto &i : *this)
                f(i);
        }

        void rebuild()
        {
            BST<T> t{};
            for (const auto &i : *this)
                t.push(i);
            *this = t;
        }

    };

    template <typename T>
    class BST<T>::Iterator
    {
    private:
        node_wrap n;
        T *value;
        bool done;

        Stack<node_wrap> stack;

        void push_left(node_wrap node)
        {
            while (node.get() != nullptr) {
                stack.push(node);
                node = node->sx;
            }
        }

    public:
        Iterator(node_wrap n_)
                : n{n_}
                , value{&n_->value}
                , done{false}
                , stack{}
        {
            push_left(n_);
            ++*this;
        }

        bool operator!=(Iterator __attribute__((unused)) _) const { return !done; }
        T &operator*() { return *value; }

        void operator++()
        {
            if (!stack.size()) {
                done = true;
                return;
            }
            auto top = stack.pop();
            if (top->dx.get()) push_left(top->dx);
            value = &top->value;
        }

    };

} // namespace dz

#endif
