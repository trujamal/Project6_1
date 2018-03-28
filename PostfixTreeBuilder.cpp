/**
 * @author Jamal Rasool
 * @version 1.0
 * @date 3/27/18
 * @details The driver functions for the logic within the code
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <exception>
#include "PostfixTreeBuilder.h"

using std::cout;
using std::endl;

/**
 * overall algorithim to follow for the code
 * postorder(node)
  if (node = null)
    return
  postorder(node.left)
  postorder(node.right)
  visit(node)
 */



/**
iterativePostorder(node)
  s ← empty stack
  lastNodeVisited ← null
  while (not s.isEmpty() or node ≠ null)
    if (node ≠ null)
      s.push(node)
      node ← node.left
    else
      peekNode ← s.peek()
      // if right child exists and traversing node
      // from left child, then move right
      if (peekNode.right ≠ null and lastNodeVisited ≠ peekNode.right)
        node ← peekNode.right
      else
        visit(peekNode)
        lastNodeVisited ← s.pop()
 */

/**
 * Constructor
 */

PostffixTreeNode::PostffixTreeNode() {

}

Number_element_nodes::Number_element_nodes(double number) : number(number) {

}








/**
 * Deconstructors
 */
PostffixTreeNode::~PostffixTreeNode() {

}

Number_element_nodes::~Number_element_nodes() {

}

/**
 * Processing Commands
 */

void Postfix_builder::processRightParenthesis() {

}

void Postfix_builder::processOperator(char op) {

}
