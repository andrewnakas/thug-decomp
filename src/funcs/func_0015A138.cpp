struct Slot { unsigned char b; char pad[3]; };
struct B { char pad[0x220]; Slot* slots; void Set(int i, unsigned char v); };
void B::Set(int i, unsigned char v) { slots[i].b = v; }
