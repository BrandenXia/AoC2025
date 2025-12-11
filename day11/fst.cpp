#include <deque>
#include <fstream>
#include <print>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

std::unordered_map<std::string, std::unordered_set<std::string>> G;

auto bfs_path(std::string_view start, std::string_view goal) {
  auto q = std::deque<std::deque<std::string_view>>{};
  q.push_back({start, start});
  auto V = std::unordered_map<std::string_view,
                              std::vector<std::deque<std::string_view>>>{};

  while (!q.empty()) {
    auto p = q.front();
    q.pop_front();
    auto node = p.front();

    V[node].emplace_back(p);

    for (const auto &n : G[std::string{node}]) {
      auto n_view = std::string_view{n};
      auto new_path = p;
      new_path.push_back(n_view);
      new_path.front() = n_view;
      q.push_back(new_path);
    }
  }

  return V[goal].size();
}

int main() {
  auto file = std::ifstream{"input.txt"};

  std::string line;
  while (std::getline(file, line)) {
    auto from = line.substr(0, line.find(":"));
    auto to = std::unordered_set<std::string>{};
    auto pos = 0;
    while ((pos = line.find(" ", pos)) != std::string::npos) {
      auto neighbor = line.substr(pos + 1, line.find(" ", pos + 1) - pos - 1);
      to.insert(std::move(neighbor));
      pos++;
    }
    G.emplace(std::move(from), std::move(to));
  }

  std::println("{}", bfs_path("you", "out"));
}
