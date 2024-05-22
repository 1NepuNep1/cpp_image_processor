# C++ Image Processor
## Eng 
### Description
Image Processor is a console application for processing BMP images (4-bit BMP without compression and color table). The application provides a set of filters for modifying images.

### Command Line Arguments Format
`{program name} {input file path} {output file path} [-{filter name 1} [filter parameter 1] [filter parameter 2] ...] [-{filter name 2} [filter parameter 1] [filter parameter 2] ...] ...`

### Main Features
The application supports the following filters:

* __Crop__ --- Crops the image to the specified width and height. Uses the upper-left part of the image. <br>
_Filter Usage_: `./image_processor input.bmp output.bmp -crop 100 150` <br><br>

* __Grayscale__ --- Converts the image to grayscale. <br>
_Filter Usage_: `./image_processor input.bmp output.bmp -gs` <br><br>

* __Negative__ --- Converts the image to negative. <br>
_Filter Usage_: `./image_processor input.bmp output.bmp -neg` <br><br>

* __Sharpening__ --- Increases the sharpness of the image. <br>
_Filter Usage_: `./image_processor input.bmp output.bmp -sharp` <br><br>

* __Edge Detection__ --- Detects edges. Pixels with a value exceeding the threshold are colored white, others are colored black. <br>
_Filter Usage_: `./image_processor input.bmp output.bmp -edge 50` <br><br>

* __Gaussian Blur__ --- [Gaussian blur](https://en.wikipedia.org/wiki/Gaussian_blur). Defined by sigma. <br>
_Filter Usage_: `./image_processor input.bmp output.bmp -blur 0.5` <br><br>

* __Coal__ --- Turns the picture into a charcoal drawing. Works well with `-neg`, turning the image into a sketch. <br>
_Filter Usage_: `./image_processor input.bmp output.bmp -coal` <br><br>

* __FishEye__ --- Distorts the image. <br>
_Filter Usage_: `./image_processor input.bmp output.bmp -fisheye` <br><br>

Examples of using all filters are available in the `image_examples` folder.

### Installation
1. Clone the repository with the project.
2. Navigate to the project directory:
```bash
cd image-processor
```
3. Build the project using CMake:
```bash
mkdir build
cd build
cmake ..
make
```
4. Run the generated `image_processor` file with the necessary parameters (running without parameters will output help):
```bash
./image_processor <input_file.bmp> <output_file.bmp> <filter> [parameters]
```

## Rus
### Описание
Image Processor - консольное приложение для обработки изображений формата BMP (4-битный BMP без сжатия и без таблицы цветов). Приложение предоставляет набор фильтров для модификации изображений.

### Формат аргументов командной строки

`{имя программы} {путь к входному файлу} {путь к выходному файлу}
[-{имя фильтра 1} [параметр фильтра 1] [параметр фильтра 2] ...]
[-{имя фильтра 2} [параметр фильтра 1] [параметр фильтра 2] ...] ...`


### Основные функции
Приложение поддерживает следующие фильтры:
* __Crop__ ---
Обрезает изображение до заданных ширины и высоты. Используется верхняя левая часть изображения. <br>
_Применение фильтра:_`./image_processor input.bmp output.bmp -crop 100 150` <br><br>

* __Grayscale__ --- Преобразует изображение в оттенки серого. <br>
_Применение фильтра:_ `./image_processor input.bmp output.bmp -gs` <br><br>

* __Negative__ --- Преобразует изображение в негатив. <br>
  _Применение фильтра:_ `./image_processor input.bmp output.bmp -neg` <br><br>

* __Sharpening__ --- Повышение резкости изображения. <br>
  _Применение фильтра:_ `./image_processor input.bmp output.bmp -sharp` <br><br>

* __Edge Detection__ --- Выделение границ. Пиксели со значением, превысившим `threshold`, окрашиваются в белый, остальные – в черный. <br>
  _Применение фильтра:_ `./image_processor input.bmp output.bmp -edge 50` <br><br>

* __Gaussian Blur__ --- [Гауссово размытие](https://ru.wikipedia.org/wiki/Размытие_по_Гауссу). Задается сигмой. <br>
  _Применение фильтра:_ `./image_processor input.bmp output.bmp -blur 0.5` <br><br>

* __Coal__ --- Превращение рисунка в картину, написанную углем. Неплохо работает с `-neg`, превращая картинку в скетч. <br>
  _Применение фильтра:_ `./image_processor input.bmp output.bmp -coal` <br><br>

* __FishEye__ --- Растягивание рисунка. <br>
  _Применение фильтра:_ `./image_processor input.bmp output.bmp -fisheye` <br><br>

Примеры использования всех фильтров есть в папке `image_examples`.
### Установка
1. Склонируйте репозиторий с проектом
2. Перейдите в директорию проекта:
```bash
cd image-processor
```
3. Соберите проект с использованием CMake:
```bash
   mkdir build
   cd build
   cmake ..
   make
```
4. Запустите собравшийся файл `image_processor` с необходимыми параметрами (запуск без параметров выведет помощь):
```bash
./image_processor <input_file.bmp> <output_file.bmp> <filter> [parameters]
```
