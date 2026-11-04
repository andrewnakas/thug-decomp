struct Strm113A70 {
    int m0;
    int m4;
    int m8;
    int mC;
};

extern "C" int func_003242E0(int fd);
extern "C" int func_00113000(Strm113A70* s);

struct File113A70 {
    char m_pad[0x50];
    int m50;
    Strm113A70* m54;
    int Close();
};

int File113A70::Close()
{
    if (func_003242E0(m50)) {
        m54->mC = 8;
        return 0;
    }
    return func_00113000(m54) == 0;
}
