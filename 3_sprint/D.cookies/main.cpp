#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main() {

   int count_of_cookies, count_of_child;

   std::cin >> count_of_child;

   std::vector<int> childs(count_of_child);

   for (int& child : childs) {
      std::cin >> child;
   }

   std::cin >> count_of_cookies;

   std::vector<int> cookies(count_of_cookies);

   for (int& cookie : cookies) {
      std::cin >> cookie;
   }

   std::sort(childs.begin(), childs.end());
   std::sort(cookies.begin(), cookies.end());

   std::queue<int> q_childs, q_cookies;
   for (const int child : childs) {
      q_childs.push(child);
   }
   for (const int cookie : cookies) {
      q_cookies.push(cookie);
   }

   int happy_kids = 0;
   while (!q_cookies.empty() && !q_childs.empty()) {
      if (q_cookies.front() >= q_childs.front()) {
         q_cookies.pop();
         q_childs.pop();
         ++happy_kids;
      } else {
         q_cookies.pop();
      }
   }

   std::cout << happy_kids;

   return 0;
}