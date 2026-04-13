#ifndef INSTANCE_LIMITER_HPP
#define INSTANCE_LIMITER_HPP

#include <cstddef>
#include <stdexcept>

template <typename Derived, std::size_t limit>
class Counter {
protected:
  Counter() { check_the_limit(); _count++; }
  Counter(const Counter&) { check_the_limit(); _count++; }
  Counter(Counter&&) { check_the_limit(); _count++; }
  ~Counter() { if (_count > 0) _count--; }

private:
  inline static std::size_t _count = 0;

  void check_the_limit() {
    if (_count >= limit) {
      throw std::runtime_error("instance limit exceeded");
    }
  }
};

#endif
