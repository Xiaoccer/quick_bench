#include <benchmark/benchmark.h>
#include <string>
#include <string_view>
#include <vector>

const char* s = "hello world";

void _use_string_view(std::string_view s) { benchmark::DoNotOptimize(s.size()); }

void _use_const_string_ref(const std::string& s) { benchmark::DoNotOptimize(s.size()); }

static void use_string_view(benchmark::State& state) {
  for (auto _ : state) {
    for (int i = 0; i < state.range(0); ++i) {
      _use_string_view(s);
    }
  }
}

static void use_const_string_ref(benchmark::State& state) {
  for (auto _ : state) {
    for (int i = 0; i < state.range(0); ++i) {
      _use_const_string_ref(s);
    }
  }
}

BENCHMARK(use_string_view)->Range(8, 8 << 10)->UseRealTime()->Unit(benchmark::kNanosecond);
BENCHMARK(use_const_string_ref)->Range(8, 8 << 10)->UseRealTime()->Unit(benchmark::kNanosecond);
BENCHMARK_MAIN();
