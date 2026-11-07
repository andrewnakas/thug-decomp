/* fuzzy: 82.3 */
struct Ent_0014CFC0 {
    int m0;
    unsigned short* m4;
};

class Snd_0014CFC0 {
public:
    char pad[0xC0];
    unsigned long mC0 : 32;
    unsigned long mFlag0 : 1;
    unsigned long mFlag1 : 1;
    void* mC8;
    char mCC[0x10];
    Ent_0014CFC0* mDC;
    int mE0;
    bool IsHidden() const { return mFlag0; }
    void Hide(int mask);
};

void Snd_0014CFC0::Hide(int mask)
{
    if (!IsHidden()) {
        for (int i = 0; i < mE0; i++) {
            if (mDC[i].m0 & mask) {
                if (mDC[i].m4) *mDC[i].m4 = 0xC000;
            }
        }
        mFlag0 = 1;
    }
}
