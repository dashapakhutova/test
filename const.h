#ifdef _CONST
#else
#define _CONST

/* Нужно добавить
 * Настройку уровня срабатывания ошибки питания
 * Гистерезис ошибки питания
 * Умолчальный уровнь ошибки питания
 * Базовый уровень ошибки питания
 */

/* Адреса страниц хранения данных
 * Это последние две страницы флэша
 */

#define FLASH_MAIN_PAGE_INDEX 14U
//0x8000000 + index * 0x800
#define FLASH_MAIN_PAGE 0x08007000

#define FLASH_BACKUP_PAGE_INDEX 15U
//0x8000000 + index * 0x800
#define FLASH_BACKUP_PAGE 0x08007800

/* Константы первой и последней ячеек данныъ
 * По ним проверяется корректность записи
 * Если обе верны, запись страницы не была оборвана посередине
 */

//0101...
#define START_KEYWORD 0x55555555

//1010...
#define END_KEYWORD 0xaaaaaaaa

/* Адреса ячеек хранимых значений
 */

/* Тип
 * 1-я ячейка
 */
#define FLASH_DATA_TYPE (8*1)

/* Артикул платы в палитре e1
 * Сейчас нигде не используется
 * Может быть, отдавать спецзапросом?
 * Четыре символа несколько портят малину
 * Версия прошивки их в принципе заменяет
 */
#define e1_gt "wct3"
#define e1_jt "grm"
#define e1_it "srcc"
#define e1_vt "a1"

#define INITIAL_SETTINGS 0

#define bool uint8_t
#define true 1
#define false 0
#endif
