struct Node_0013AE48 {
    char pad[0x10];
    Node_0013AE48* m10;
};

extern Node_0013AE48* D_0038A07C;
extern "C" void func_0013ADA8(Node_0013AE48* n, int a, int b);
extern "C" void func_0013ADD8(Node_0013AE48* n, int c, int d);

extern "C" Node_0013AE48* func_0013AE48(int a, int b, int c, int d)
{
    Node_0013AE48* n = D_0038A07C;
    if (n)
        D_0038A07C = n->m10;
    func_0013ADA8(n, a, b);
    func_0013ADD8(n, c, d);
    return n;
}
