# RGB LED

Ein RGB LED Board, ursprünglich entwickelt für den Ferienpass Rapperswil, durchgeführt mit 8 Teilnehmenden im Oktober 2014. Die Teilnehmer waren ca. 10 Jahre alt.

## Version 1

Die Version 1 besteht aus Potis für jede RGB-Farbe. Der Strom wird **nur** durch die Potis geregelt. Im Gegensatz zu V2 besitzt V1 auch noch keinen Schalter zur Stromzufuhr - es kann also lediglich eine Stromquelle angeschlossen oder vom Board getrennt werden.

![foto v1][photo-v1-back]

## Version 2

Die Version 2 verwendet einen Arduino Nano als Controller, welcher im Gegenzug drei MOSFETs verwendet um die RGB LEDs per PWM zu dimmen. Dadurch ist es möglich auch grössere Streifen mit RGB LEDs anzusteuern.


[photo-v1-back]: https://raw.githubusercontent.com/coredump-ch/rgb-led/master/v1/photo_v1_back.jpg
