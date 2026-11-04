struct Strm113AC0 {
    int m0;
    int m4;
    int m8;
    int mC;
};

extern "C" int func_00323B80(int fd);
extern "C" int func_00113000(Strm113AC0* s);

struct File113AC0 {
    char m_pad[0x50];
    int m50;
    Strm113AC0* m54;
    int Flush();
};

int File113AC0::Flush()
{
    if (func_00323B80(m50)) {
        m54->mC = 8;
        return 0;
    }
    return func_00113000(m54);
}
