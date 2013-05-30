int main() {
  int* p = new int(1);
  return *p;
}
void g(int* a) {}

void f() {
  int a[] = {1, 2, 3};
  int* p = a;
  g(a);
}
int h() {
  int *p = new int(2);
  return *p;
}
void h(int* p) {
  int a[2] = {2, 3};
  p = a;
  return;
}
