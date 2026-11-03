struct Strm113988 {
    int m0;
    int m4;
    int m8;
    int mC;
};

extern "C" int func_00323830(int fd);
extern "C" int func_00113000(Strm113988* s);

struct File113988 {
    char m_pad[0x50];
    int m50;
    Strm113988* m54;
    int Close();
};

int File113988::Close()
{
    if (func_00323830(m50)) {
        m54->mC = 8;
        return 0;
    }
    return func_00113000(m54) == 0;
}
