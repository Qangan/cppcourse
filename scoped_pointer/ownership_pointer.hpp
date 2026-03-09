template <typename T> class OwnershipPointer {
  T *pointer;

public:
  OwnershipPointer(T *raw) : pointer(raw) {}
  OwnershipPointer(const OwnershipPointer &other) = delete;
  OwnershipPointer(OwnershipPointer &&other) {
    pointer = other.pointer;
    other.pointer = nullptr;
  }

  OwnershipPointer &operator=(const OwnershipPointer &other) = delete;

  OwnershipPointer &operator=(const OwnershipPointer &&other) {
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
  ~OwnershipPointer() { delete pointer; }
};
