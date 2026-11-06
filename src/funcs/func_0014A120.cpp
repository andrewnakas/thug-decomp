class Node_0014A120 {
public:
    int m0;
    short m4;
    void* m8;
    int mC;
    virtual ~Node_0014A120();
};

extern "C" void func_00165058(Node_0014A120* o);

extern "C" int func_0014A120(Node_0014A120* o)
{
    func_00165058(o);
    delete o;
    return 1;
}
