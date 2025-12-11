#include <fstream>
#include <print>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>

std::unordered_map<std::string, std::unordered_set<std::string>> G;

struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);
    return h1 ^ h2;
  }
};

auto cntp(std::string_view u, std::string_view t) {
  static auto memo =
      std::unordered_map<std::pair<std::string_view, std::string_view>,
                         unsigned long, pair_hash>{};

  if (auto it = memo.find({u, t}); it != memo.end())
    return it->second;

  if (u == t)
    return 1ul;
  if (auto it = G.find(std::string{u}); it == G.end())
    return 0ul;

  auto total = 0ul;
  for (const auto &v : G[std::string{u}]) {
    auto res = cntp(v, t);
    memo[{u, t}] = res;
    total += res;
  }

  memo[{u, t}] = total;
  return total;
}

int main() {
  using namespace std::literals::string_view_literals;

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

  auto start = "svr"sv;
  auto out = "out"sv;
  auto fft = "fft"sv;
  auto dac = "dac"sv;

  auto s2dac = cntp(start, dac);
  auto dac2fft = cntp(dac, fft);
  auto fft2out = cntp(fft, out);

  auto s2fft = cntp(start, fft);
  auto fft2dac = cntp(fft, dac);
  auto dac2out = cntp(dac, out);

  auto total = s2dac * dac2fft * fft2out + s2fft * fft2dac * dac2out;
  std::println("{}", total);
}
