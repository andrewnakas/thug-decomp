struct Card_001139D8 {
    int m0;
    int m_port;
    int m_slot;
    int m_error;
};

extern "C" int func_003238F0(int fd, int offset, int whence);
extern "C" int func_00113000(Card_001139D8* card);

struct File_001139D8 {
    char pad[0x50];
    int m_fd;
    Card_001139D8* m_card;
    int Seek(int offset, int origin);
};

int File_001139D8::Seek(int offset, int origin)
{
    int whence;
    switch (origin) {
    case 0:
        whence = 0;
        break;
    case 1:
        whence = 1;
        break;
    case 2:
        whence = 2;
        break;
    default:
        whence = 1;
        break;
    }
    if (func_003238F0(m_fd, offset, whence)) {
        m_card->m_error = 8;
        return 0;
    }
    return func_00113000(m_card);
}
