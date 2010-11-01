#include "demo.h"
#include <iostream>


MyDemo::MyDemo(QObject *parent):QObject(parent){

    qDebug() <<" MyDemo Constructor ";
}

void MyDemo::quitEventLoop(){

        this->loopptr->quit();

    }
gboolean bus_call (GstBus *bus,GstMessage *msg,gpointer    data)
{
        MyDemo *local =(MyDemo *) data;

        switch (GST_MESSAGE_TYPE (msg)) {

                case GST_MESSAGE_EOS:{
                        qDebug() << "End of stream\n";
                        local->quitEventLoop();
                        break;
                }

                case GST_MESSAGE_ERROR: {
                        gchar  *debug;
                        GError *error;

                        gst_message_parse_error (msg, &error, &debug);
                        g_printerr ("Error: %s\n", error->message);
                        g_free (debug);

                        qDebug() <<"GST_MSG Error";
                        g_error_free (error);

                        local->quitEventLoop();

                        break;
                }
                default:
                        break;
        }

        return TRUE;
}



QString MyDemo::SayBye(){

    QString str = " !!!!  Bye !!!!";
#if 0
    QDir directory_path(QDir::home());
    const QString str_path = directory_path.path()+"/MyDocs/music/Darling-Neeve.Mp3";
    //const QString str_path = directory_path.path()+"/Darling-Neeve.Mp3";
    char *file_path = str_path.toAscii().data();

    //QString absolutePath = directory.absoluteFilePath("contents.txt");
    qDebug() << "file path of song :"<< str_path;
    qDebug() << str_path.toAscii().data();
    gchar *act_gpath=NULL;
    act_gpath = g_strndup(file_path,strlen(file_path));
    g_message("gchar path : %s",act_gpath);
#endif
    gchar *file_path ="/home/suman/Darling-Neeve.Mp3";

    QEventLoop loop ;
    this->loopptr = &loop;

    //if(!QFile::exists (str_path))
      //  g_message("!!! file not present !!!");

    /*creating a piple line*/
            GstElement *somePipeline = gst_pipeline_new("somePlayerPipe");


            GstElement* source  = gst_element_factory_make ("filesrc","file-source");
            g_object_set(source,"location",file_path,NULL);

            GstElement* audio_decoder  = gst_element_factory_make ("mad","audio_decoder");
            GstElement* audio_converter  = gst_element_factory_make ("audioconvert","converter");
            GstElement* audio_resample= gst_element_factory_make ("audioresample","resample");
            GstElement* osssink= gst_element_factory_make ("osssink","osssink");

            if(!source || !audio_decoder || !audio_converter || !audio_resample || !osssink)
            {
                    qDebug()<<"one element could not be created";
                    return str;
            }

            GstBus* somePlayerBus = gst_pipeline_get_bus(GST_PIPELINE(somePipeline));
           gst_bus_add_watch(somePlayerBus,bus_call,this);
            gst_object_unref(somePlayerBus);

            gst_bin_add_many (GST_BIN (somePipeline),source,
                    audio_decoder, audio_converter, audio_resample, osssink, NULL);

            /* we link the elements together */
            /* file-source -> audio-decoder -> converter -> resample -> osssink */
            gst_element_link_many (source, audio_decoder, audio_converter,audio_resample, osssink, NULL);
            /* Set the pipeline to "playing" state*/
            qDebug() << "Now playing:";
            gst_element_set_state(somePipeline,GST_STATE_PLAYING);
            loop.exec();

            /* out of mainloop,*/
            gst_element_set_state(somePipeline,GST_STATE_NULL);
            gst_object_unref(GST_OBJECT(somePipeline));

    return str;

}
void MyDemo::SayHello(const QString &name, const QVariantMap &customdata){
    qDebug() <<"!!! Hello !!!";

}

