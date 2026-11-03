struct Strm113B10 {
    int m0;
    int m4;
    int m8;
    int mC;
};

extern "C" int func_00323A68(int fd);
extern "C" int func_00113000(Strm113B10* s);

struct File113B10 {
    char m_pad[0x50];
    int m50;
    Strm113B10* m54;
    int Flush();
};

int File113B10::Flush()
{
    if (func_00323A68(m50)) {
        m54->mC = 8;
        return 0;
    }
    return func_00113000(m54);
}
