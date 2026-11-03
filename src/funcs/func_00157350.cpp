struct Slot { unsigned char b; char pad[3]; };
struct Obj157350 { char pad[0x220]; Slot* slots; void Set(int i, unsigned char v); };
void Obj157350::Set(int i, unsigned char v) { slots[i].b = v; }
