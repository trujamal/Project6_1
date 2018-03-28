//
// Created by Greg LaKomski on 3/16/18.
//

#ifndef HOMEWORK6_INFIXTREEBUILDER_H
#define HOMEWORK6_INFIXTREEBUILDER_H



#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <exception>

using std::cout;
using std::endl;

class ExpressionElementNode
{
 public:
  virtual double value() = 0; // Return the value of this node.
};

class NumericElementNode: public ExpressionElementNode
{

 private:
  double number;
  NumericElementNode();
  NumericElementNode(const NumericElementNode& n);
  NumericElementNode&operator=(const NumericElementNode& n);

 public:
  NumericElementNode(double val);
  virtual double value();  // dont need virtual
};





class BinaryOperationNode: public ExpressionElementNode
{

 private:

  char binary_op;

  ExpressionElementNode *left;
  ExpressionElementNode *right;

  BinaryOperationNode(const BinaryOperationNode& n);
  BinaryOperationNode();
  BinaryOperationNode &operator=(const BinaryOperationNode& n);

 public:
  BinaryOperationNode(char op, ExpressionElementNode *l,
                      ExpressionElementNode *r);

  virtual double value();  // dont need virtual
};



class BinaryExpressionBuilder
{

 private:
  // holds either (, +, -, /, or *
  std::stack<char> operatorStack;

  // operandStack is made up of BinaryOperationNodes and NumericElementNode
  std::stack<ExpressionElementNode *> operandStack;

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

  BinaryOperationNode *parse(std::string& istr) throw (NotWellFormed);
};




#endif //HOMEWORK6_INFIXTREEBUILDER_H
