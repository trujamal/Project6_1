/**
 * @author Jamal Rassool
 * @version 1.0
 * @date 3/27/18
 * @details Program designed to handle the Post Fix Tree Traversal of values. The Oriignal .h file that Greg Gave Us
 * Can remain the same due to it only setting up the stack logic that will contain the information. Within the .cpp file
 * that is where the main logic will occur in which one will modify the program from infix to postfix by going and
 * referencing the node last.
 */

#include "algorithm"
#include "iostream"
#include <cstdlib>
#include "string"
#include <stack>


#ifndef PROJECT6_1_POSTFIXTREEBUILDER_H
#define PROJECT6_1_POSTFIXTREEBUILDER_H


using std::cout;
using std::endl;


class PostffixTreeNode
{
public:
    PostffixTreeNode();

    virtual double value() = 0;

    virtual ~PostffixTreeNode();
    // Return the value of this node.
};

class Number_element_nodes: public PostffixTreeNode
{

private:
    double number;
    Number_element_nodes();
    Number_element_nodes(const Number_element_nodes& n);
    Number_element_nodes&operator=(const Number_element_nodes& n);

public:
    Number_element_nodes(double num);

    double value();

    virtual ~Number_element_nodes();
};

class Postfix_builder
{

private:
    // holds either (, +, -, /, or *
    std::stack<char> operatorStack;

    // operandStack is made up of BinaryOperationNodes and NumericElementNode
    std::stack<PostffixTreeNode *> operandStack;

    void processOperator(char op);

    void processRightParenthesis();

    void doBinary(char op);

    int precedence(char op);

public:

    class NotWellFormed: public std::exception
    {

    public:
        virtual const char* what() const throw ()
        {
            return "The expression is not valid";
        }
    };

    PostffixTreeNode *parse(std::string& istr) throw (NotWellFormed);
};

#endif //PROJECT6_1_POSTFIXTREEBUILDER_H
