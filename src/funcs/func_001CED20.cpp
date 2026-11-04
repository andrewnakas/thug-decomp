struct Mgr {
    char pad[0xAC];
    unsigned int mAC;
};

extern Mgr* D_00392808;

struct Watcher {
    char pad[0x20];
    int m20;
    void Update();
};

void Watcher::Update()
{
    m20 = D_00392808->mAC != 0xD443A2BC;
}
