class Shared_001F2C10 {
public:
    int m_pad[5];
    virtual ~Shared_001F2C10();
};

extern Shared_001F2C10* D_0038E8A4;
extern unsigned int D_0038E8A8;

void Release_001F2C10()
{
    if (D_0038E8A8 > 1) {
        D_0038E8A8--;
        return;
    }
    if (D_0038E8A4)
        delete D_0038E8A4;
    D_0038E8A4 = 0;
    D_0038E8A8 = 0;
}
