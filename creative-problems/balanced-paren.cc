/* This program prompts the user to enter a string
 * of parentheses and returns 'balanced', 'unbalanced',
 * or 'invalid entry' based on the input. 
 *
 * A string of balanced parentheses are parentheses
 * such that every opening parentheses (which may
 * be brackets, or braces as well) has a corresponding
 * closing parentheses. Furthermore for each pair of 
 * opening and closing parentheses, it must be the case
 * that the opening parentheses (again, it may be a 
 * bracket '[', or braces '{'), must precede its 
 * corresponding closing parentheses.
 *
 * For example: 
 * 
 * (()) 
 *
 * The parentheses above is balanced because each '(' 
 * has a corresponding ')'.
 *
 * ((]]
 *
 * The parentheses above is not balanced because each
 * '(' doesn't have a ')' matching it, and ditto for
 * ']'.
 *
 *
 * ((]][[))
 *
 *
 * In the avoe parentheses, observe that there are an equal
 * of parentheses, '(', ')', and brackets '[', ']'. However
 * the parentheses are not balanced because closing 
 * brackets precede their corresponding opening braces.
 *
 */

 #include <iostream>
 #include <string>
 #include <stack>
 using namespace std;
 
 enum ParenType {O_PAREN, C_PAREN, O_BRACKET, C_BRACKET, O_BRACE, C_BRACE, INVALID};

 ParenType getParenType(char c) {
  switch(c) {
    case '(':
      return O_PAREN;
      break;
    case ')':
      return C_PAREN;
      break;
    case '[':
      return O_BRACKET;
      break;
    case ']':
      return C_BRACKET;
      break;
    case '{':
      return O_BRACE;
      break;
    case '}':
      return C_BRACE;
      break;
    default: 
      return INVALID;
      break;
  }
 }

 int main(int argc, char *argv[]) {
  string s;
  
  cout << "Enter a string of balanced parentheses: ";
  while(getline(cin,s)) {
    stack<ParenType> stack;
      size_t i = 0;
      size_t sz = s.size();

      for(int i = 0; i < s.size(); i++) {
        ParenType type = getParenType(s[i]);
        if(type == INVALID) {
          cerr << "Invalid entry." << endl;
          exit(0);
        }

        if(type % 2 == 0) { // open 
          stack.push(type);
        } else {
          if(stack.empty() || stack.top() != type - 1) {
            cerr << "Unbalanced." << endl;
            exit(0);
          } else {
            stack.pop();
          }
        }
      }
      if(!stack.empty()) {
        cout << "Unbalanced" << endl;
      } else {
        cout << "Balanced" << endl;
      }

      cout << "Enter a string of balanced parentheses: ";
  }
      
  return 0;
 }

