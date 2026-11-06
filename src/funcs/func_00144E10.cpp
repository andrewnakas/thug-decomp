/* Constructor of a 0xA00-byte block holding four 64-entry tables whose entry constructor is empty. */
struct Entry_00144E10 {
    short m_v[5];
    Entry_00144E10() {}
};

struct Tables_00144E10 {
    Entry_00144E10 m_a[64];
    Entry_00144E10 m_b[64];
    Entry_00144E10 m_c[64];
    Entry_00144E10 m_d[64];
    Tables_00144E10();
};

Tables_00144E10::Tables_00144E10()
{
}
