extern "C" int func_00331BB8(const char* s);

struct Str_00104110 {
    int m0;
    int m4;
    char* m_buf;
    int m_size;
    Str_00104110& operator=(const char* s);
};

extern "C" void func_001041C0(Str_00104110* self, const char* s, int start, int end);

Str_00104110& Str_00104110::operator=(const char* s)
{
    int end = 0;
    if (s) {
        end = func_00331BB8(s) - 1;
        if (end < 0) {
            end = 0;
        }
    }
    func_001041C0(this, s, 0, end);
    return *this;
}
