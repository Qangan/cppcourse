template <typename T> class CopyPointer {
  T *pointer;

public:
  CopyPointer(T *raw) : pointer(raw) {}
  CopyPointer(const CopyPointer &other) {
    pointer = other.pointer ? new T(*other.pointer) : nullptr;
  }
  CopyPointer(CopyPointer &&other) {
    pointer = other.pointer;
    other.pointer = nullptr;
  }

  CopyPointer &operator=(const CopyPointer &other) {
    if (this != other) {
      delete pointer;
      pointer = other.pointer ? new T *(other.pointer) : nullptr;
    }
    return *this;
  }

  CopyPointer &operator=(const CopyPointer &&other) {
    if (this != other) {
      delete pointer;
      pointer = other.pointer;
      other.pointer = nullptr;
    }
    return *this;
  }

  T &get() { return *pointer; }
  const T &get() const { return *pointer; }
  T &operator*() { return *pointer; }
  const T &operator*() const { return *pointer; }
  T *operator->() { return pointer; }
  const T *operator->() const { return pointer; }
  ~CopyPointer() { delete pointer; }
};
