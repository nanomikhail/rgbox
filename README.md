# Программируемый полноцветный фонарь RGBox 
![Image from Gyazo](https://i.gyazo.com/26d2f47c99378f52cf53724f9b46aaec.jpg)

  Этот проект создавался для того чтобы повысить качество и креативность фотографий делаемых мной на зеркальный фотоаппарат. 
  Итоговое устройство представляет из себя небольшой коробок, с одним единственным управляющим элементом - энкодером, с помощью него осуществляется навигация по меню режимов, и управление параметрами режима. Так же он оснащён небольшим 0.96" OLED дисплеем, который отображает всю нужную информацию. Фонарик питается от встроенного li-ion аккумулятора на 600 мА, которого хватает на 40 минут непрерывной работы в режиме максимальной мощности, чего предостаточно, учитывая что на фотографию требуется считанные секунды. Гланый элемент фонарика - светодиодная матрица распаянная на макетной плате, каждый светодиод является трехцветным и адресным, и тк они соединены последовательно, фонарик способен контроллировать цвет и яркость каждого отдельного светодиода, что позволяет добиться необычных эффектов, таких как например цветные тени.
  Такой фонарик очень пригодится любителям снимать фризлайт

![Image from Gyazo](https://i.gyazo.com/1e113de932292714dc0e8ef044e6bf6e.jpg)

Удерживанием кнопки энкодера открывает меню режимов. Рассмотрим каждый:  
- RGB MIXER - Миксер красного, зелёного и синего каналов, в этом режиме можно накрутить любой из 16 млн оттенков цветов.
- COLOR SHADOWS - Хитрый режим, позволяющий добиться разноцветных теней, чем  то похоже на glitch фильтры в фоторедакторах.
- STROBOSCOPE - Просто стробоскоп, можно менять частоту мерцания.
- ASTROLIGHT - Регулируемый по яркости красный свет, очень полезен астрономам, тк не снижает чувствительность глаза в темноте.
- BAD RAIDBOW - Переливающаяся радуга, "BAD" из-за несовершенности алгоритма смены цвета.
- RANDOM COLOR - Генерация случайного цвета по клику.

И вот таких интересных эффектов удалось добиться с этим фонариком:
![Image from Gyazo](https://i.gyazo.com/9ce0a5af4b9649b37ee9050a10cb371c.jpg)



- Для получения полной инструкции и схем для повторения проекта прошу написать мне на электронную почту: crossx500@gmail.com
