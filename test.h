#ifndef TEST_H
#define TEST_H


class Test {

public:
    Test(const unsigned int &value);
    void fun1();
    void fun2();
    void _delete_();

private:
    int *ptr;
};

#endif // TEST_H
