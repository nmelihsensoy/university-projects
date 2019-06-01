string choiceQuestion = "Secim: ";
string pageMenuTextEN[] = {"#", "Ekle", "Duzenle", "Sil", "Yazdir", "Ara", "Ana Menu", "Cikis"};
string menuTextEN[] = {"Servis Otomasyonu " ,"Servisler", "Rotalar", "Yolcular", "Araclar", "Suruculer", "Cikis"}; 
string devMenuTextEN[] = {"Shuttle Automation[DEV] ", "Create Mock Data", "Exit"};
string outputFileNameSTR = "Dosya adi giriniz: ";
string deleteEnterSTR = "ID Giriniz: ";

//<Shuttles>//
string shuttles_questions[] = {"ID Giriniz: ", "Durum Seciniz: ", "Tip Seciniz: ", "Guzergah Seciniz: ", "Departman Giriniz: ", "Arac Seciniz: ", "Sofor Seciniz: ", "Calistigi Gunleri Giriniz: ", "$"};
string shuttles_desc[] = {"\n", "0-Pasif  1-Aktif\n\n", "1-Gunduz, 2-Aksam, 3-Ozel\n\n", file_db[1].getStyledContent(), "", file_db[3].getStyledContent(), file_db[4].getStyledContent(), "P, S, C, Pe, Cu, Cmt, Pz \n gibi araya virgullu giriniz. \n\n", "$"};
//</Shuttles>//

//<Routes>//
string routes_questions[] = {"ID Giriniz: ", "Guzergah Adi Giriniz: ", "Duraklari Giriniz: "};
string routes_desc[] = {"\n", "", ""};
//</Routes>//

//<Vehicles>//
string vehicles_questions[] = {"ID Giriniz: ", "Marka Giriniz: ", "Kontenjan Giriniz: ", "Plaka Giriniz: "};
string vehicles_desc[] = {"\n", "", "", ""};
//</Vehicles>//

//<Drivers>//
string drivers_questions[] = {"ID Giriniz: ", "Surucu Adı Giriniz: ", "$"};
string drivers_desc[] = {"\n", "", "$"};
//</Drivers>//

//<Passengers>//
string passengers_questions[] = {"ID Giriniz: ", "Ad-Soyad Giriniz: ", "Servis Seciniz: ", "Binecegi Duragi Seciniz: "};
string passengers_desc[] = {"\n", "", file_db[0].getStyledContent(), file_db[1].getStyledContent()};
//</Passengers>//