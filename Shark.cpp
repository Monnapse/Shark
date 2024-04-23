#include <string>
#include "Shark.h"
#include "Arduino.h" 

Page::Page()
{

} 

void Page::AddHTMLLine(String  Line)
{
  PageContents = PageContents + Line;
}

String Page::GetHTML()
{
  return PageContents;
}

//PageStruct::PageStruct(String Name, Page& PageObject)
//{
//  PageName = Name;
//  PageClass = PageObject;
//}

Shark::Shark()
{

}

String Shark::Render()
{
  String PageContent = "";
  PageContent += "HTTP/1.1 200 OK"
  //Page.AddHTMLLine("HTTP/1.1 200 OK");
  //Page.AddHTMLLine("Content-type:text/html");
  //Page.AddHTMLLine("Connection: close");
  //Page.AddHTMLLine();
}

void Shark::AddPage(String PageName, Page& PageClass)
{
  PageArray[sizeof(PageArray)] = PageClass.GetHTML();
  //PageStruct PageItem(PageName, PageClass);
  //PageList.add(PageItem);
}

void Shark::AddMedia(String Blob) 
{
  MediaArray[sizeof(MediaArray)] = Blob;
  //MediaList.add(Blob);
}