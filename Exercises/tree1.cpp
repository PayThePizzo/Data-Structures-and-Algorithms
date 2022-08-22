#include <memory>
#include <stdexcept>
#include <functional>
#include <type_traits>
#include <string>
#include <cstring>

namespace cpp17 {

    struct nullopt_t {} nullopt;

    template <typename T>
    struct optional {
        T *t = nullptr;

        optional(nullopt_t) {}
        optional(const T &t) : t{new T(t)} {}

        optional(const optional<T> &other) {
            if (other) {
                optional(other.get());
            }
        }

        optional(optional<T> &&other) {
            if (other) {
                optional(other.get());
            }
        }

        ~optional() { delete t; }

        bool operator==(const optional<T> &other) { return *t == *other.t; }
        bool operator>=(const optional<T> &other) { return *t >= *other.t; }
        bool operator<=(const optional<T> &other) { return *t <= *other.t; }
        bool operator>(const optional<T> &other)  { return *t > *other.t;  }
        bool operator<(const optional<T> &other)  { return *t < *other.t;  }

        operator bool() const { return t != nullptr; }

        T &get() { return *t; }
        const T &get() const { return *t; }

        template <typename R>
        optional<R> and_then(std::function<R(T)> f) {
            return *this
                   ? optional<R>(f(get()))
                   : nullopt;
        }

        template <typename R>
        optional<R> or_else(std::function<R()> f) {
            return !*this
                   ? optional<R>(f())
                   : *this;
        }

        T value_or(T &&d) {
            return *this
                   ? *t
                   : d;
        }
    };

    template<typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }

    template <typename char_t = char>
    struct string_view {
        const char_t *b = nullptr;
        const char_t *e = nullptr;
        const unsigned long int  size;

        string_view() : b{nullptr}, e{nullptr}, size{0} {}

        string_view(const char*s)
                : b{s}
                , e{s + std::strlen(s)}
                , size{std::strlen(s)} {}

        string_view(std::string &&s) : b{s.begin()}, e{s.end()}, size{s.size()} {}
        string_view(const std::string::const_iterator &b, const std::string::const_iterator &e) : b{&*b}, e{&*e}, size{e - b} {}

        string_view(const std::string &s, unsigned size)
                : b{s.begin()}
                , e{s.begin() + size}
                , size{size} {}
    };

    std::ostream& operator<<(std::ostream& os, const cpp17::string_view<char> &s) {
        os << std::string(s.b, s.e);
        return os;
    }

    template <typename char_type>
    struct supafast_string {
        // TODO implement flystring and string_view in same class to optimize all the shits
    };

}

#include <vector>
#include <iostream>
#include <unordered_map>
#include <iomanip>

// TODO optimize string with cpp17::string_view

enum class Kind {
    None,
    OpenPar,
    ClosedPar,
    Plus,
    Minus,
    Times,
    Number,
};

std::unordered_map<Kind, const char*> KindToStr{{
                                                        {Kind::None, "None"},
                                                        {Kind::OpenPar, "OpenPar"},
                                                        {Kind::ClosedPar, "ClosedPar"},
                                                        {Kind::Plus, "Plus"},
                                                        {Kind::Minus, "Minus"},
                                                        {Kind::Times, "Times"},
                                                        {Kind::Number, "Number"},
                                                }};

enum class Type {
    Function,
    Expression,
    Integer,
};

std::unordered_map<Type, const char*> TypeToStr{{
                                                        {Type::Function, "Function"},
                                                        {Type::Expression, "Expression"},
                                                        {Type::Integer, "Integer"},
                                                }};

std::string padding(int n) {
    std::string s;
    for (int i = 0; i < n * 4; i++) {
        s += ' ';
    }
    return s;
}

struct ASTNode {
    Type type;
    cpp17::string_view<char> identifier;
    std::vector<ASTNode> children;

    void print(int indent = 0) const {
        std::cout << padding(indent) << "Type: " << TypeToStr[type] << std::endl;
        if (identifier.size) {
            std::cout << padding(indent) << "Identifier: " << identifier << std::endl;
        }
        if (children.size()) {
            std::cout << padding(indent) << "Children: " << std::endl;
            for (const auto c : children) {
                c.print(indent + 1);
            }
        }
    }
};

struct Token {
    Kind kind;
    cpp17::string_view<char> value;
};

struct Lexer {
    const std::string source;
    decltype(source.cbegin()) cur = source.cbegin();
    decltype(source.cend()) end = source.cend();

    bool has_next() const {
        return cur != end;
    }

    cpp17::optional<Token> next() {
        if (!has_next()) {
            return cpp17::nullopt;
        }

        switch (*cur) {
            case '(': cur++; return Token{Kind::OpenPar};
            case ')': cur++; return Token{Kind::ClosedPar};
            case '+': cur++; return Token{Kind::Plus};
            case '-': cur++; return Token{Kind::Minus};
            case '*': cur++; return Token{Kind::Times};
            default:
                if (isdigit(*cur)) {

                    auto b = cur;
                    auto e = cur;
                    while (isdigit(*cur)) {
                        e++;
                        cur++;
                    }

                    return Token{Kind::Number, cpp17::string_view<char>{b, e}};
                }

                cur++;
                return Token{Kind::None};
        }
    }
};

struct Parser {
    Lexer l;

    std::vector<ASTNode> parse_expr() {
        std::vector<ASTNode> children = {};

        while (l.has_next()) {
            auto t = l.next().get();
            switch (t.kind) {
                case Kind::ClosedPar: return children;
                case Kind::OpenPar:
                    children.push_back({Type::Expression, "", parse_expr()});
                    break;
                case Kind::Number:
                    children.push_back({Type::Integer, t.value, {}});
                    break;
                case Kind::Plus:
                    children.push_back({Type::Function, "plus", {}});
                    break;
                case Kind::Minus:
                    children.push_back({Type::Function, "minus", {}});
                    break;
                case Kind::Times:
                    children.push_back({Type::Function, "times", {}});
                    break;
            }
        }

        return children;
    }

    ASTNode parse() {
        while (l.has_next()) {
            auto t = l.next().get();
            switch (t.kind) {
                case Kind::OpenPar:
                    return {Type::Expression, "", parse_expr()};
                default:
                    return {};
            }
            std::cout << KindToStr[t.kind] << " " << t.value << std::endl;
        }

        return {};
    }

    int eval() {
        auto ast = parse();
        ast.print();
        return 0;
    }
};

int main() {
    using cpp17::optional;

    auto v = optional<int>{3};

    auto w = v
            .and_then<float>([=](int i) { return 5.0f; })
            .and_then<std::string>([](float f) { return ""; })
            .or_else<float>([=]() { return 1.0f; })
            .value_or(6.0f);


    Parser p{"(54815+464*(648-413))"};
    p.eval();

    return w;
}