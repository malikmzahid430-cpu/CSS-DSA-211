#include<iostream>
#include<stack>
#include<string>
#include<deque>
#include<queue>

// question no 01 ---------------- part a ------------------------
/*int main()
{
	std::string input;
	std::stack<char> s;
	std::cout << "Enter the input"<<std::endl;
	std::getline(std::cin, input);

	for (char i : input)
		s.push(i);

	while (!s.empty()){

		std::cout << s.top();
		s.pop();
	}


}*/
// question no 01 ---------------- part b ------------------------
//int main()
//{
//	std::string input;
//	std::stack<char> s;
//	std::stack<char> s1;
//	std::cout << "Enter the input"<<std::endl;
//	std::getline(std::cin, input);
//
//	for (char i : input)
//		s.push(i);
//
//	while (!s.empty()) {
//
//		while (!s.empty() && s.top() != ' ') {
//			s1.push(s.top());
//			s.pop();
//		}
//		while (!s1.empty()) {
//
//			std::cout << s1.top();
//			s1.pop();
//		}
//		if (!s.empty()){
//			std::cout << " ";
//			s.pop();
//		}
//	}
//}


// question no 02 ---------------- part b ------------------------



/*int main()
{
    std::string input;
    std::stack<char> s;
    std::stack<int> position;

    std::cout << "Enter input: ";
    std::getline(std::cin, input);

    for (int i = 0; i < input.length(); ++i){
        char ch = input[i];

        if (ch == '(' || ch == '[' || ch == '{'){
            s.push(ch);
            position.push(i);
        }

        else if (ch == ')' || ch == ']' || ch == '}'){
            if (s.empty()){
                std::cout << "Error at " << i << ": unexpected closer";
                return 0;
            }

            char top = s.top();

            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')){
                char expected;

                if (top == '(')
                    expected = ')';
                else if (top == '[')
                    expected = ']';
                else
                    expected = '}';

                std::cout << "Error at " << i << ": expected '" << expected << "' but found '" << ch << "'";
                return 0;
            }

            s.pop();
            position.pop();
        }
    }

    if (!s.empty())
        std::cout << "Error at " << position.top() << ": unclosed opener";
    else
        std::cout << "Balanced";

    return 0;
}*/


// question no 06
// two stack class
/*template<typename T>
class TwoStackQueue
{
private:
    std::stack<T> instack;
    std::stack<T> outstack;

    // transfer values function
    void transfer_data(){
        if (outstack.empty()){
            while (!instack.empty()){
                outstack.push(instack.top());
                instack.pop();
            }
        }
    }

public:
    // push function
    void push(const T& value){
        instack.push(value);
    }

    // pop function
    void pop(){
        transfer_data();
        if (!outstack.empty())
            outstack.pop();
    }

    // front function
    T& front(){
        transfer_data();

        if (outstack.empty())
            std::cout << "Queue is empty!";

        return outstack.top();
    }


    bool empty() const{
        return instack.empty() && outstack.empty();
    }

    int size() const{
        return instack.size() + outstack.size();
    }
};

int main()
{
    TwoStackQueue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    std::cout << "Front: " << q.front() << std::endl;
    q.pop();
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Size: " << q.size() << std::endl;
    return 0;
}
*/


// question no 03

int main()
{
    std::queue<int> q;
    int n, k;

    std::cout << "Enter number of players: ";
    std::cin >> n;
    std::cout << "Enter k: ";
    std::cin >> k;

    for (int i = 1; i <= n; i++)
        q.push(i);

    std::cout << "Eliminated: ";

    while (q.size() > 1){
        for (int i = 0; i < k; i++){
            q.push(q.front());
            q.pop();
        }
        std::cout << q.front() << " "<<std::endl;
        q.pop();
    }
    std::cout << "Winner: " << q.front();
    return 0;
}