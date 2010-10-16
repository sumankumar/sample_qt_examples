#include <QApplication>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QDebug>
#include <QXmlStreamAttributes>

int main(int argc , char * argv[])
{
    QApplication app(argc,argv);

    QFile file("writefile.xml");
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug()<< "Unable to open the file";
    }


    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();

    writer.writeStartElement("XmlOfflineData");
    writer.writeStartElement("StationData");

    writer.writeTextElement("StationId","MyProCo");
    writer.writeTextElement("LineId","xy");
    writer.writeTextElement("PhaseId","111");
    writer.writeTextElement("AdapterId","222");
    writer.writeTextElement("ReportPath","./home");


    writer.writeEndElement();
    writer.writeEndElement();

    writer.writeStartElement("root");

    writer.writeStartElement("Header");
    writer.writeTextElement("Project_A","success");
    writer.writeEndElement();

    writer.writeEndElement();

    writer.writeEndDocument();

    file.close();
#if 1

    QFile file1("writtenfile.xml");
    if(!file1.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<< "Unable to open the file";
    }

    QXmlStreamReader reader(&file1);

    //reader.setDevice(&file1);
    reader.readNext();

    while (!reader.atEnd())
    {
        if(reader.isStartElement())
        {
            while(reader.name() != NULL)
            {
                qDebug() <<reader.name();
                //qDebug() << "\t"<<reader.readElementText();
                if(reader.readElementText() == ""){
                    qDebug() <<"no text element";
                    //break;
                }
#if 1
            else if(reader.name() == "StationId")
                qDebug() << "\t"<< reader.readElementText();
            else if(reader.name() == "StationId")
                qDebug() << "\t"<< reader.readElementText();
            else if(reader.name() == "LineId")
                qDebug() << "\t"<< reader.readElementText();
#endif

            }

        }
 reader.readNext();
        //else
          //  reader.readNextStartElement();



    }

    //reader.
    file1.close();
#endif
    return 0;

}
