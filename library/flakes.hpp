//TODO: Add All Includes here. 1:33 AM 3/4/21
#ifndef PARSER_VALIDATOR
// Start Token Validator

/*
 * Token validator can parse expressions and either return the evaluated problem,
 * or return the evaluated expression.
 *
 *
 * EG
 *
 * 1 + 2 = 3
 *
 * Evaluated problem:
 *
 * true
 *
 * Evaluated Expression
 *
 * {INT} + {INT} = {EXPR}
 */
#include <cctype>

namespace std {
    namespace parsers {
        namespace validator {
            bool valid_if_num_is_valid(const std::string& expr) {

                bool f = std::stoi(expr);

                return f;

            }
            std::string exprconst(std::string expr) {
                for (int i = 0; i < expr.size(); ++i) {
                    if (isdigit(expr[i])) {
                        expr[i] = '{';
                        expr.push_back('I');
                        expr.push_back('N');
                        expr.push_back('T');
                        expr.push_back('}');
                    }
                    else {
                        expr[i] = '{';
                        expr.push_back('S');
                        expr.push_back('T');
                        expr.push_back('R');
                        expr.push_back('}');
                    }
                }
            }
        }
    }
}
#endif
#ifndef PARSER_VARIABLES_H
//
// Created by seymo on 3/3/2021.
//
#include <fstream>
#include <vector>
#include <iostream>

#ifndef FLAKES_VARIABLES_H
#define FLAKES_VARIABLES_H
namespace std {
    namespace names {
        enum name {
            TYPE_NAME,
            TYPE_VALUE
        };
    }
    namespace filetypes {
        enum filetype {
            YAML,
            HTML,
            TD,
            C,
            NONE
        };
    }
    namespace parsers {
        struct basic_parser {
            char variable_delim;
            const char* file;

            // Create a YML File while EOF != true
            // Mainly used as a debug feature to test if the parser is working correctly.
            void start_log(std::filetypes::filetype type) const {
                if (type == filetypes::YAML) {
                    std::ifstream parseable(file);
                    if (!parseable)
                        return;

                    std::string val;
                    std::string key;
                    while (getline(parseable, key, variable_delim) && getline(parseable, val, '\n')) {
                        std::ofstream out("out.yml", std::ios::app);
                        out << "variable:\n\tname: " << key << "\n\tvalue: " << val << std::endl;
                        out.close();
                    }
                }
                else if (type == filetypes::NONE) {
                    // Do nothing. . .
                }
                else if (type == filetypes::HTML) {
                    std::ifstream parseable(file);
                    if (!parseable)
                        return;

                    std::string val;
                    std::string key;
                    std::ofstream out("out.html", std::ios::app);
                    out << "<h1>This file was generated by flakes, A Giant C++ STL Extension that enhances coding.</h1>\n\n<div about=\"this.encoding().toString().validJSON.Data.Returned(1)\">\n" << std::endl;
                    out.close();
                    while (getline(parseable, key, variable_delim) && getline(parseable, val, '\n')) {
                        std::ofstream outf("out.html", std::ios::app);
                        outf << "<pre>this:\n\tname: " << key << "\n\t\tval: " << val << std::endl;
                        outf.close();
                    }
                    std::ofstream outf("out.html", std::ios::app);
                    outf << "\n</div>" << std::endl;
                    outf.close();
                }
            }
            // Used to test if variables are able to be returned. Returns a string with all valid variables using namespace variable_delim and getline()
            void return_vars(std::names::name e) const {
                std::ifstream parseable(file);
                if (!parseable)
                    std::cout << "Failed at return_vars()" << std::endl;;
                std::vector <std::string> vars{};
                std::string val;
                std::string key;
                while (getline(parseable, key, variable_delim) && getline(parseable, val, '\n')) {
                    if (e == names::TYPE_NAME)
                        vars.push_back(key);
                    else if (e == names::TYPE_VALUE)
                        vars.push_back(val);
                }
                for (auto & var : vars) {
                    if (var[var.size()] != '\n')
                        std::cout << var << ",";
                }
            }
        };

    }
}
#endif //FLAKES_VARIABLES_H
#endif
#ifndef JSON
#include <iostream>
#include <fstream>
#include "../lib/json.hpp"
namespace std {
    namespace json {
        auto link(const char* path) {
            std::ifstream iile(path);
            nlohmann::json string1 = nlohmann::json::parse(iile);
            return string1;
        }
    }


}
#endif
//
// Created by seymo on 3/4/2021.
//

#ifndef FLAKES_TIME_H
#define FLAKES_TIME_H
#include <cstdlib>
#include <windows.h>

namespace std {
    namespace timermodes {
        enum Time {
            TIMER_END,
            TIMER_BEGIN,
            TIMER_MID
        };
    }
    void sleep(int time) {
        Sleep(time * 1000);
    }
    struct clock {
        virtual bool wait_if(timermodes::Time mode, int secs) const noexcept {
            if (mode == timermodes::TIMER_BEGIN)
                return true;
            else if (mode == timermodes::TIMER_MID) {
                Sleep(secs / 2);
                return true;
            }
            else if (mode == timermodes::TIMER_END) {
                Sleep(secs * 1000);
                return true;
            }
        }
    };
}


#endif //FLAKES_TIME_H
//
// Created by seymo on 3/4/2021.
//

#ifndef FLAKES_MAKE_H
#define FLAKES_MAKE_H

#include <fstream>

namespace std {
    namespace makefiles {
        struct makefile {
            std::string name;
            std::string ext;
        };
        void makefileconcat(makefile& make) {
            std::ifstream sfile(make.name + make.ext);
            std::string foo;
            std::string lineargs;
            while (sfile >> foo) {
                getline(sfile, lineargs, '\n');
                system((foo += " " + lineargs).c_str());
            }
        }
    }
}
#endif //FLAKES_MAKE_H
//
// Created by seymo on 3/7/2021.
//

#ifndef FLAKES_BETTERMATH_H
#define FLAKES_BETTERMATH_H

namespace std {
    namespace bettermath {
        int half_of(int c) {
            return c / 2;
        }
        double half_of(double c) {
            return c / 2;
        }
        float half_of(float c) {
            return c / 2;
        }
        int pemdas(const std::string& expr) {
            return std::stoi(expr);
        }
        bool switch_expr(const std::string construct) {
            bool exprf = std::stoi(construct);
            return exprf;
        }
        int five_points_up(int c) {
            return c + 5;
        }
        int ten_points_up(int c) {
            return c + 10;
        }

    }
}

#endif //FLAKES_BETTERMATH_H
//
// Created by seymo on 3/8/2021.
//

#ifndef FLAKES_PROTO_HPP
#define FLAKES_PROTO_HPP

#include <iostream>

void MAKE(const char* v) {
    std::cout << "nullptr" << std::endl;
}

namespace std {
    struct BASIC_TEMPLATE {


        std::string value;

        std::string id;
        std::string  uuid;
        std::string link;

    public:
        BASIC_TEMPLATE() {
            this->value = "null";
            this->uuid = "none";
            this->link = "none";
            this->id = "abc";
        }
        explicit BASIC_TEMPLATE(const std::string& ths) {
            value = ths;
        }
        BASIC_TEMPLATE(const std::string& ths, const std::string& uuid ,const std::string& link, const std::string& id) {
            this->value = ths;
            this->uuid = uuid;
            this->link = link;
            this->id = id;
        }
        template<typename op>
        op& operator==(const char* thi) {
            if (this->value == thi) {
                return true;
            }
            else {
                return nullptr;
            }

        }
    } ;
    template<typename T>
    BASIC_TEMPLATE& aTemplate(const T&& s) {
        return s;
    }
    BASIC_TEMPLATE temp("L");

    template<typename open>
    open&& opened() {
        return false;
    }

}

#endif //FLAKES_PROTO_HPP
//
// Created by seymo on 3/8/2021.
//
#include <iostream>

#ifndef FLAKES_BETTER_STDOUT_HPP
#define FLAKES_BETTER_STDOUT_HPP
namespace std {
    void sprint(const char *T) {
        std::cout << T << std::endl;
    }

    void PUTS(const std::string &th) {
        std::cout << th << std::endl;
    }

    void puts_t(const std::string &tis) {
        std::cout << tis << std::endl;
    }
}
// HeaderDef Macros
#define PRINTS(CHAR) std::puts_t(CHAR)
#define S_PUTS(CHAR) std::PUTS(CHAR)
#define PRINT(CHAR) std::sprint(CHAR)

#endif //FLAKES_BETTER_STDOUT_HPP
