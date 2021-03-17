#include <iostream>
#include <vector>
#include <stdexcept>
#include "snowman.hpp"

using namespace std;
const int stringLength = 8;

const vector<string> Head = {"       \n _===_ ", "  ___  \n ..... ", "   _   \n  /_\\  ", "  ___  \n (_*_) "};
const vector<string> Nose = {",", ".", "_", " "};
const vector<string> Eyes = {".", "o", "O", "-"};
const vector<string> LHandUp = {" ", "\\", " ", " "};
const vector<string> LHandDown = {"<", " ", "/", " "};
const vector<string> RHandUp = {" ", "/", " ", " "};
const vector<string> RHandDown = {">", " ", "\\", " "};
const vector<string> Torso = {"( : )", "(] [)", "(> <)", "(   )"};
const vector<string> Base = {" ( : ) ", " (\" \") ", " (___) ", " (   ) "};

static void rangeCheck(string input)
{
    if (input.size() != stringLength){
        throw invalid_argument{"ERROR: The input string must be 8 characters long.\n"};
    }

    for (int i = 0; i < input.size(); i++){
        if (input[i] < '1' || input[i] > '4'){
            throw invalid_argument{"ERROR: The input string must contain numbers from 1 to 4.\n"};
        }
    }
}

int organ(char c)
{
    return c - '0' - 1;
}

namespace ariel
{
    string snowman(int input)
    {
        string output;
        string rules = to_string(input);
        rangeCheck(rules);

        enum organs {h , n , l , r , x , y , t , b}; // Like the letters in the snowman assignment page
        string hat = Head[organ(rules[h])];
        string bodyUP = LHandUp[organ(rules[x])] + "(" + Eyes[organ(rules[l])] + Nose[organ(rules[n])] + Eyes[organ(rules[r])] +
                         ")" + RHandUp[organ(rules[y])];
        string bodyDown = LHandDown[organ(rules[x])] + Torso[organ(rules[t])] + RHandDown[organ(rules[y])];
        string base = Base[organ(rules[b])];

        return hat + "\n" + bodyUP + "\n" + bodyDown + "\n" + base;
    }
};

