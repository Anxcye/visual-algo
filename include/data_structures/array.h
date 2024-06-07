#ifndef ARRAY_H
#define ARRAY_H

class Array {
public:
    Array(int size);
    ~Array();

    int getSize() const;
    int get(int index) const;
    void set(int index, int value);

private:
    int* data;
    int size;
};

#endif // ARRAY_H
