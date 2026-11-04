struct Slot { unsigned char b; char pad[3]; };
struct Obj158840 { char pad[0x220]; Slot* slots; void Set(int i, unsigned char v); };
void Obj158840::Set(int i, unsigned char v) { slots[i].b = v; }
