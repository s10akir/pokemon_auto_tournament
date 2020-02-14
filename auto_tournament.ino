#include <SwitchControlLibrary.h>

void connect() {
  SwitchControlLibrary();

  SwitchControlLibrary().PressButtonL();
  delay(500);
  SwitchControlLibrary().PressButtonR();
  delay(500);
  SwitchControlLibrary().ReleaseButtonL();
  delay(500);
  SwitchControlLibrary().ReleaseButtonR();
  delay(500);

  // 認識待ちに一応1秒マージン置く
  delay(1000);
}

void PressAndReleaseButtonA(int del) {
  SwitchControlLibrary().PressButtonA();
  delay(del);
  SwitchControlLibrary().ReleaseButtonA();
  delay(del);
}

void PressAndReleaseButtonB(int del) {
  SwitchControlLibrary().PressButtonB();
  delay(del);
  SwitchControlLibrary().ReleaseButtonB();
  delay(del);
}

void setup() {
  connect();
}

void loop() {
  // 受付と試合開始のために右上に走り続ける
  SwitchControlLibrary().MoveLeftStick(191, 0);

  // A連打ときどきBキャンセル
  for (int i = 0; i < 10; i++) {
    PressAndReleaseButtonA(250);
  }
  PressAndReleaseButtonB(250);
}
