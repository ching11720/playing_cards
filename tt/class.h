template <typename T>
class Tclass{
public:
    Tclass(int);
    ~Tclass();
    
    T get(int);
    void set(int, T);
private:
    int size;
    T* array;
};
