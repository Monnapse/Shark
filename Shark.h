#ifndef SHARK_H
#define SHARK_H
#include "Arduino.h" 

class Page
{
  public:
    Page();

    void AddHTMLLine(String Line);
    String GetHTML();
  private:
    String PageContents;
};

struct PageStruct
{
  String PageName;
  Page PageClass;

  PageStruct(String Name, Page& PageObject) : PageName(Name), PageClass(PageObject) {}
};

class Shark
{
    public:
      Shark();
      
      void AddPage(String PageName, Page& PageClass);
      void AddMedia(String Blob);
      String Render();

    private:
      String MediaDirectoryName = "static";
      String MediaArray[10];
      String PageArray[10];
};

#endif