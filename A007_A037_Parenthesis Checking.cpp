#include<iostream>
#include<stack>
using namespace std;
bool isBalanced(string expr) {
   stack<char> s;
   char ch;
   for (int i=0; i<expr.length(); i++) {
   	if (expr[i]=='('||expr[i]=='['||expr[i]=='{'||expr[i]==')'||expr[i]==']'||expr[i]=='}')
   	{
      if (expr[i]=='('||expr[i]=='['||expr[i]=='{') {    //when it is opening bracket, push into     stack
         s.push(expr[i]);
         continue;
      }
      if (s.empty())    //stack cannot be empty as it is not opening bracket, there must be closing     bracket
         return false;
         switch (expr[i]) {
            case ')':    //for closing parenthesis, pop it and check for braces and square brackets
               ch = s.top();
               s.pop();
               if (ch=='{' || ch=='[')
                  return false;
                  break;
            case '}': //for closing braces, pop it and check for parenthesis and square brackets
               ch = s.top();
               s.pop();
               if (ch=='(' || ch=='[')
                  return false;
                  break;
            case ']': //for closing square bracket, pop it and check for braces and parenthesis
               ch = s.top();
               s.pop();
               if (ch =='(' || ch == '{')
                  return false;
                  break;
         }
      }
      else
      continue;
  }
      return (s.empty()); //when stack is empty, return true
}
main() {
   string expr = "[{a-b}(k)*{d-(b)}]";
   cout<<"Expression: "<<expr;
   if (isBalanced(expr))
      cout << "\n\nBalanced expression.";
   else
      cout << "\n\nUnbalanced expression.";
}
