#include <benchmark/benchmark.h>
#include <string>
#include <vector>

const std::string s = "hello world";

static void no_reserve(benchmark::State& state) {
  for (auto _ : state) {
    std::vector<std::string> v;
    for (int i = 0; i < state.range(0); ++i) {
      benchmark::DoNotOptimize(v.emplace_back(s));
      benchmark::ClobberMemory();
    }
  }
}

static void reserve(benchmark::State& state) {
  for (auto _ : state) {
    std::vector<std::string> v;
    v.reserve(state.range(0));
    for (int i = 0; i < state.range(0); ++i) {
      benchmark::DoNotOptimize(v.emplace_back(s));
      benchmark::ClobberMemory();
    }
  }
}

BENCHMARK(no_reserve)->Range(8, 8 << 10)->UseRealTime()->Unit(benchmark::kNanosecond);
BENCHMARK(reserve)->Range(8, 8 << 10)->UseRealTime()->Unit(benchmark::kNanosecond);
BENCHMARK_MAIN();
