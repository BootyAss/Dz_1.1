All needed files included (so now they are really)
##all updates are marked as "upd::"

```Shell
DB - the DataBase class, contains vector of Units
Unit - base class, "Подразделение"
SciUnit - derived class, "Научный"
EduUnit - derived class, "Образовательный"

Functions - header with functions (out, error, parsing, etc.)
Paths - header with paths to an object/directory

Source - only main() function
```
upd:: ## Так же добавил 6 файлов с готовыми примерами Баз Данных .txt (DB0,DB1,DB2,DB3,DB4,DB01), DB01 - копия DB1, может быть удалена для тестирования функции delete

## Для реализации я выбрал не самый разумный пусть - создал класс DB с вектором Unit* и использовал map<string, Unit*> в main. Думаю, легче было создать вектор имен string и обращаться к классу через это имя для получения данных.

## help - функция для вызова всех доступных команд

#Команды
  ## В списке Баз данных :
  ```Shell
 help
 create <DB name> - создание новой Базы Данных
 list - вывод списка Баз Данных
 show <DB name> - вывод списка Подразделений в Базе Данных <DB name>
 amount - вывод кол-ва студентов во всех Базах данных
 amount <DB name> 
 find <Unit name> - вывод имен Баз Данных, сожержащих Подразделение с именем <Unit name> 
 find <Head name>
 upd:: remove all - удаление всех Баз Данных из памяти (.txt файлы не трогаются)
 upd:: remove <DB name>
 upd:: delete all - удаление всех .txt файлов из директории, с содержанием информации о Базе Данных
 upd:: delete <DB name> 
 upd:: edit <DB name> - изменение параметров Базы Данных #Для сохранения изменений сохраните Базу Данных (save <DB name>)
 clear - очистка консоли
 head <Head name> - вывод Подразделений, которые возглавляет <Head name>
 staff <amount> - вывод Подразделений, у которых кол-во работников превышает amount
 save - запись всех Баз Данных в <DB name>.txt файлы
 read <DB name> - чтение информации из <DB name>.txt файла 
 read all - чтение информации из всех .txt файлов в директории
 path show - показать путь к папке с файлами "База Данных"
 path change - изменить путь к папке
 by_staff - сортировка по кол-ву работников в Базе Данных
 by_name - сортировка Баз Данных по названиям подразделения
 <DB name> - функция для работы с определенной Базой данных
 end - завершить работу программы
 ```
 
 ## В Базе данных :
   ```Shell
 help
 create <Unit name>
 list
 show <Unit name>
 amount
 amount <DB name>
 find <Head name>
 upd:: remove all
 upd:: remove <Unit name>
 current - вывести название текущей Базы Данных
 clear
 head <Head name>
 staff <amount>
 save
 read <DB name>
 read all
 path show
 path change
 by_staff - will sort and show DB list only, not Unit list
 by_name -  will sort and show DB list only, not Unit list
 back
 end
```

upd:: Добавил несколько методов в классы для реализации функций, проверил на ошибки, вызванные неправильным вводом параметров пользователем.
