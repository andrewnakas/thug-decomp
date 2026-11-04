struct Obj170B68 {
    int m0;
    int m4;
    int m8;
    void* Data(int* size);
};

void* Obj170B68::Data(int* size)
{
    int n = m8;
    char* p = (char*)this + m4;
    *size = n;
    return n ? p : 0;
}
