# Shuttle Automation

**A shuttle service automation software for companies. All code comments, class-variable-function names are written in English. All the text below there are written in Turkish.Maybe i write them in English too.**

Bir şirket için personal servis otomasyonu yazılımı.

## Rapor
Projemi C++ dilinde Nesne Yönelimli Programlama paradigması kullanan bir konsol uygulaması olarak yazdım.Toplamla 4 tane sınıf kullandım.Bu sınıflardan '**AddListSearch**' sınıfı sadece dosya için satır ekleme, arama ve listeleme işlemlerini yapar. '**DeleteUpdate**' sınıfı dosya için satır silme ve güncelleme işlemlerini yapar. 

Projemdeki en önemli sınıf olan '**FileDb**' sınıfı ise üstte bahsettiğim 2 sınıftan miras alır. Listelenen satırların bölümlere parçalanması, verilerin dosyaya yazılabilir hale getirilmesi ve yazılması, parçalanan verilerin görsel olarak iyi ve anlışılabilir hale getirilmesi, 
kullanıcı girdilerinin alınması, kullanılması ve şimdi bahsedeceğim filtreleme özelliğinin tablolara uygulanması gibi önemli işlevleri yerine getirir.Projemde bulunan Servis, Güzergah, Araç, Yolcu ve Sürücü modüllerini bu sınıfı kullanarak ürettim. Ayrıca bu sınıfları mümkün olduğunca esnek yazmaya çalıştım. Yani veritabanı olarak düz dosyaları kullanacağım bir konsol uygulaması yazmak istersem bu sınıfı tekrar kullanabilirim.

'**CustomFilters**' sınıfı ile tablodaki verileri sınıf içerisinde veya dosyada herhangi bir değişiklik yapmadan manipule etmeyi amaçladım. Yani tabloda satır-sütün değerlerine, tablodaki değerin ne olduğuna göre görsel değişiklikler yapabiliyorum.Örneğin dosyada 1 olarak yazılan veriyi tabloda 'Açık' olarak, 0 olan veriyi 'Kapalı' olarak yazdırma.2 veya daha fazla tabloyu birbirine satır numarasına göre bağlama.Tablodaki bütün verilerdeki boşluk karakterini silme ve benzeri işlemleri bu sınıf ile yapabiliyorum.

## Dokümantasyon
Projede kullandığım sınıfların değişkenleri ve fonksiyonların neler olduğu ve ne iş yaptıklarını kısa cümleler ile burada belirttim.

## AddListSearch Sınıfı
|  |  |
| ------------ | ------------ |
| **Miras Aldığı Sınıflar:** | Yok |
| **Yapıcı Fonksiyonları:**  | Yok  |
| **Yıkıcı Fonksiyonları:**   | Yok |

### Değişkenler
|Erişim | Tip  | İsim | Açıklama  |
|------------ | ------------ | ------------ | ------------ |
| protected | *string*  | ***fileName***  | Veritabanı dosyasının adını saklar.  |
| protected |  *string* | **tempFileName**  | Geçici dosyanın adını saklar.  |
| protected |  *int* |  **dataCount** | Veri sayısını saklar.  |

### Fonksiyonlar
| Erişim  | Tip  | İsim  | Açıklama  |
| ------------ | ------------ | ------------ | ------------ |
| protected | *void*  | **ekle**(*string* line)  | Dosyaya satır ekler. |
| protected  | *bool*  | **isFileExist**()  | Dosyanın var olup olmadığını kontrol eder.  |
| protected  | *void*  | **listele**(*string* *list)  | Satırları kaydeder ve sayar.  |
| virtual protected | *string* | **ara**(*string* str) | Dosyada arama yapar ve kelimenin bulunduğu satırı döndürür. |

## DeleteUpdate Sınıfı
|||
| ------------ | ------------ |
|  **Miras Aldığı Sınıflar:** | Yok |
| **Yapıcı Fonksiyonları:**  | Yok  |
| **Yıkıcı Fonksiyonları:**   | Yok |

### Değişkenler
|Erişim | Tip  | İsim | Açıklama  |
|------------ | ------------ | ------------ | ------------ |
| protected | *string*  | ***fileName***  | Veritabanı dosyasının adını saklar.  |
| protected |  *string* | **tempFileName**  | Geçici dosyanın adını saklar.  |

### Fonksiyonlar
| Erişim  | Tip  | İsim  | Açıklama  |
| ------------ | ------------ | ------------ | ------------ |
| protected | *void*  | **sil**(*string* line)  | Dosyadan satır siler. |
| protected  | *void*  | **sil**(*int* line_int)  | Sayıya göre satırı siler. |
| protected  | *void*  | **guncelle**(*string* old_line, *string* new_line)  | Satırı günceller. |
| protected  | *void*  | **guncelle**(*int* old_line_int, *string* new_line)  | Satır sayısına göre satırı günceller.  |

## FileDb Sınıfı

|||
| ------------ | ------------ |
|  **Miras Aldığı Sınıflar:** | AddListSearch, DeleteUpdate  |
| **Yapıcı Fonksiyonları:**  | *FileDb*(*string* fileName, *string* * headlines,  *int* * length,  *int* size)  |
| **Yıkıcı Fonksiyonları:**   | *~FileDb()*  |

### Değişkenler
|Erişim | Tip  | İsim | Açıklama  |
|------------ | ------------ | ------------ | ------------ |
| private | *string*  | ***fileName***  | Veritabanı dosyasının adını saklar.  |
| private |  *string* | **tempFileName**  | Geçici dosyanın adını saklar.  |
| private |  *string* | **cachedFileContent[100]**  | Dosyadaki satırları saklar.  |
| private |  *string* | **styledContent**  | Verinin yazdırılabilir halini saklar.  |
| private |  *int* | **sectionCount**  | Satırdaki bölüm sayısını saklar.  |
| private |  *int* * | **sectionLength**  | Bölümlerin uzunluğunu saklar. |
| private |  *string* * | **headlines**  | Bölüm başlıklarını saklar. |
| private |  *string* | **headlinesSTR**  | Başlıkların yazdırılabilir halini saklar. |
| private |  *string* | **seperatorSTR**  | Satır çizgilerinin yazdırılabilir halini saklar.|
| private |  *stringstream* | **outputSTR**  | Yazdırılabilir halinin akısı.  |
| public |  *CustomFilters*  * | **filter**  | Uygulanacak filtreleri tutar. |
| public |  *int* | **filterCount**  | Uygulanacak filtre sayısını saklar.  |

### Fonksiyonlar
| Erişim  | Tip  | İsim  | Açıklama  |
| ------------ | ------------ | ------------ | ------------ |
| public | *void*  | **cacheFileContent**()  | Dosya satırlarını ve sayısını değişkene kaydeder. |
| public  | *int*  | **getLineCount**()  | Satır sayısını döndürür. |
| public  | *string*  | **dbOutput**(*string* *entry) | Verileri dosyaya yazılabilir hale getirir. |
| public  | *void*  | **addEntry**(*string* *entry) | Dosyaya yeni veri ekler.  |
| public  | *void*  | **addWithInput**(*string* *questions, *string* *descriptions, *int* mode) | Her bölüm için kullanıcıdan veri alır ve moduna göre veri ekler veya günceller. |
| public  | *void*  |**deleteWithInput**(*string* question) | Kullanıcı girişine göre veri siler.  |
| public | *string* | **getDataByPos**(*int* line, *int* section) | İstenilen satır ve bölüm içindeki veriyi döndürür. |
| public | *string* * | **getDataByLine**(*int* line) | Satırdaki verileri döndürür. |
| public | *string* * | **getDataBySection**(*int* section) | Bölümdeki tüm verileri döndürür. |
| public | *void* | **getDataBySectionStatic**(*int* section, string* test) | Bölümdeki tüm verileri döndürür. |
| public | *string* * | **getFreqBySectionId**(int count, int secId) | Satır sayısı frekansını döndürür.Hangi satırdan kaç tane olduğunu. |
| public | *void* | **cacheStatics**() | Başlıkları ve ayraçı yazdılabilir hale getirir. |
| public | *void* | **cacheStyledContent**() | Verilere filtreleri uygular. |
| public | *void* | **printStyledContent**() | Filtrelenmiş verileri yazdırır. |
| public | *void* | **updateCaches**() | Dosyadaki verileri yeniden alır ve filtreleri yeniden uygular. |
| public | *string* | **getStyledContent**() | Filtrelenmiş verilerin yazdırmaya hazır halini döndürür. |
| public | *void* | **fileOutput**(*string* fileName) | Filtrelenmiş veriyi dosyaya yazdırır. |
| public | *void* | **printList**(*int* listWidth, *string* * listItems,  *int*  listCount) | Listeyi stil eklenmiş halinde yazdırır. |
| public | *void* | **yaz**(*int* listWidth, *string* * listItems, *int* listCount)| Listeyi stil eklenmiş halinde yazdırır.  |
| public | *void* | **yaz**()| Filtrelenmiş veriyi yazdırır.  |
| public | *string* | **ara**(*string* str) | Dosyada arama yapar ve kelimenin bulunduğu satırı döndürür. |

## CustomFilters Sınıfı
|||
| ------------ | ------------ |
|  **Miras Aldığı Sınıflar:** | Yok |
| **Yapıcı Fonksiyonları:**  | *CustomFilters*()  |
| **Yıkıcı Fonksiyonları:**   | *~CustomFilters*() |

### Değişkenler
|Erişim | Tip  | İsim | Açıklama  |
|------------ | ------------ | ------------ | ------------ |
| private | *string*  | ***sectionInput***  | Filtrenin bulunduğu iterasyondaki bölüm içeriğini saklar.  |
| private |  *int* |  **lineCount**  | Filtrenin bulunduğu iterasyondaki satır numarasını saklar.  |
| private |  *int* |  **sectionCount**  | Filtrenin bulunduğu iterasyondaki satırın toplam bölme sayısını saklar.  |
| private |  *int* |  **currentSectionId**  | Filtrenin bulunduğu iterasyondaki bölüm numarasını saklar.  |
| private |  *string* |  **sectionOutput**  | Filtrenin uygulanmış yazdırılmaya hazır halini saklar.  |
| public |  *int* |  **sectionId**  | Filtrenin uygulanacağı bölüm numarasını saklar. Verici tarafı değişkeni. |
| public |  *int* |  **mode**  | Hangi filtrenin uygulanacağını saklar. Verici tarafı değişkeni. |
| public |  *string* * |  **bindKey**  | Filtre için anahtar kelimeleri saklar.Verici tarafı değişkeni. |
| public |  *int* |  **keySize**  | Anahtar kelime sayısını saklar.Verici tarafı değişkeni |
| public |  *string* * |  **bindVal**  | Değer kelimelerini saklar. Verici tarafı değişkeni. |
| public |  *int* |  **valSize**  | Değer kelime sayısını saklar.Verici tarafı Değişkeni.|
| public |  *string* * |  **extraBindVal**   | Değer kelimelerini saklar. Verici tarafı değişkeni. |
| public |  *string* * |  **extraBindVal2**   | Değer kelimelerini saklar. Verici tarafı değişkeni. |
| public |  *string* * |  **preSuffix**   | Önad ve sonad değerlerini saklar.Verici tarafı değişkeni. |
| public |  *stringstream * |  **ss**   | Kullanılacak akı değişkeni. |

### Fonksiyonlar
| Erişim  | Tip  | İsim  | Açıklama  |
| ------------ | ------------ | ------------ | ------------ |
| private | *void*  | **stringTrade**() | Filteyi uygular ve son çıktıyı oluşturur. |
| public  | *void*  | **setBinding**(*string* * key, *int* keyS, *string* * val, *int* valS) | Bağlayıcı ayarlar. Verici tarafı fonksiyonu. |
| public  | *void*  | **initFilter**(*string* sectionInput, *int* sectionCount, *int* lineCount, *int* currentSectionId) | Filtreyi başlatır. Alıcı tarafı fonksiyonu. |
| public  | *string*  | **getOutput**()  | Son çıktıyı döndürür.Alıcı tarafı fonksiyonu. |
| public  | *void*  | **runFilter**()  | Filtreyi Çalıştırır. Alıcı tarafı fonksiyonu. |








