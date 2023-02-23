#include <memory>

template <typename T>
class Optional {
private:
  enum Stat { OPT, NULLOPT };

  std::unique_ptr<T> ele;
  Stat stat;

public:

  friend class Nullopt;

  Optional(const T &element) {
    ele = std::unique_ptr<T>(new T(element));
    stat = OPT;
  }

  Optional() { stat = NULLOPT; }

  bool operator==(const Optional<T> &rhs) {
    return this->stat == rhs.stat && (!this->stat || this->ele == rhs.ele);
  }

  bool isNone() const {
    return stat == NULLOPT;
  }

  const T &&get() {
    stat = NULLOPT;
    return std::move(*ele.release());
  }

};

class Nullopt {
public:
  const static Nullopt nullopt;

  template<typename T> operator Optional<T>() const {
    return Optional<T>();
  }
};


