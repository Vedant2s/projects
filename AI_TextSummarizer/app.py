# Import the tkinter library and alias it as 'tk' for convenience in the code
import tkinter as tk
#from pydub import AudioSegment
# Import the 'speech_recognition' library and alias it as 'sr' for speech recognition functionality
import speech_recognition as sr
# Import all classes and functions from the 'tkinter' library to create a graphical user interface
from tkinter import *
# Import the 'ttk' module from the 'tkinter' library to access themed Tkinter widgets
from tkinter import ttk
# Import all classes and functions from the 'scrolledtext' module within the 'tkinter' library
from tkinter.scrolledtext import *
# Import the 'time' module for various time-related operations and functions
import time
# Get the current date and time in a specific format and store it in 'timestr'
timestr=time.strftime("%Y %m month %d date - %H hr %M min %S sec")
# Import the 'filedialog' module from the 'tkinter' library
import tkinter.filedialog
#NLP Packages
from spacy_summarization import text_summarizer
# from nltk_summarization import nltk_summarizer
from spacy_summarization import text_summarizer

from nltk_summarization import nltk_summarizer

# Web Scraping Pkg
from bs4 import BeautifulSoup
from urllib.request import urlopen
window =Tk()
window.title("Summaryzer GUI")
window.geometry('800x700')
#Style
style=ttk.Style(window)
style.configure('lefttab.TNotebook',tabposition='wn')
# Tabs
tab_control = ttk.Notebook(window, style='lefttab.TNotebook')
tab1 = ttk.Frame(tab_control)
tab2 = ttk.Frame(tab_control)
tab3 = ttk.Frame(tab_control)
tab4 = ttk.Frame(tab_control)
tab5 = ttk.Frame(tab_control)
tab6 = ttk.Frame(tab_control)
tab7 = ttk.Frame(tab_control)  # Added Speech to Text tab

# Add tabs to notebook
tab_control.add(tab1, text=f'{"Home":^20s}')
tab_control.add(tab2, text=f'{"File":^20s}')
tab_control.add(tab3, text=f'{"URL":^20s}')
tab_control.add(tab4, text=f'{"Comparer":^20s}')
tab_control.add(tab5, text=f'{"About":^20s}')
tab_control.add(tab6, text=f'{"Speech to Text":^20s}')
tab_control.add(tab7, text=f'{"Audio File Processing":^20s}')   # Added Speech to Text tab
tab_control.pack(expand=1, fill='both')
#function
def get_summary():
   raw_text=entry.get('1.0',tk.END)
   final_text=text_summarizer(raw_text)
   print(final_text)
   result='\nSummary : {}'.format(final_text)
   tab1_display.insert(tk.END,result)
def clear_text():
   entry.delete('1.0',END)
def clear_display_result():
   tab1_display.delete('1.0',END)
def save_summary():
   raw_text=entry.get('1.0',tk.END)
   final_text=text_summarizer(raw_text)
   file_name='your summary '+ timestr +".txt"
   with open(file_name,'w') as f:
      f.write(final_text)
   result='\nName of file {},\nSummary : {}'.format(file_name,final_text)
   tab1_display.insert(tk.END,result)
# Functions for TAB 2 FILE PROCESSER
# Open File to Read and Process
def openfiles():
	file1 = tkinter.filedialog.askopenfilename(filetypes=(("Text Files",".txt"),("All files","*")))
	read_text = open(file1).read()
	displayed_file.insert(tk.END,read_text)


def get_file_summary():
	raw_text = displayed_file.get('1.0',tk.END)
	final_text = text_summarizer(raw_text)
	result = '\nSummary:{}'.format(final_text)
	tab2_display_text.insert(tk.END,result)
# Clear Text  with position 1.0
def clear_text_file():
	displayed_file.delete('1.0',END)
# Clear Result of Functions
def clear_text_result():
	tab2_display_text.delete('1.0',END)
# Clear For URL
def clear_url_entry():
	url_entry.delete(0,END)
def clear_url_display():
	tab3_display_text.delete('1.0',END)
# Fetch Text From Url
def get_text():
	raw_text = str(url_entry.get())
	page = urlopen(raw_text)
	soup = BeautifulSoup(page)
	fetched_text = ' '.join(map(lambda p:p.text,soup.find_all('p')))
	url_display.insert(tk.END,fetched_text)

def get_url_summary():
	raw_text = url_display.get('1.0',tk.END)
	final_text = text_summarizer(raw_text)
	result = '\nSummary:{}'.format(final_text)
	tab3_display_text.insert(tk.END,result)	
# COMPARER FUNCTIONS

def use_spacy():
	raw_text = str(entry1.get('1.0',tk.END))
	final_text = text_summarizer(raw_text)
	print(final_text)
	result = '\nSpacy Summary:{}\n'.format(final_text)
	tab4_display.insert(tk.END,result)

def use_nltk():
	raw_text = str(entry1.get('1.0',tk.END))
	final_text = nltk_summarizer(raw_text)
	print(final_text)
	result = '\nNLTK Summary:{}\n'.format(final_text)
	tab4_display.insert(tk.END,result)

def use_gensim():
	raw_text = str(entry1.get('1.0',tk.END))
	final_text = "comming soon"
	print(final_text)
	result = '\nGensim Summary:{}\n'.format(final_text)
	tab4_display.insert(tk.END,result)

def use_sumy():
	raw_text = str(entry1.get('1.0',tk.END))
	final_text = text_summarizer(raw_text)
	print(final_text)
	result = '\nSumy Summary:{}\n'.format(final_text)
	tab4_display.insert(tk.END,result)
# Clear entry widget
def clear_compare_text():
	entry1.delete('1.0',END)

def clear_compare_display_result():
	tab4_display.delete('1.0',END)
def start_listening():
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
        try:
            text_output.config(state=tk.NORMAL)
            text_output.delete('1.0', tk.END)
            text_output.insert(tk.END, "Listening...\n")
            text_output.config(state=tk.DISABLED)
            while True:
                audio_data = recognizer.listen(source)
                text = recognizer.recognize_google(audio_data)
                text_output.config(state=tk.NORMAL)
                text_output.insert(tk.END, text + '\n')
                #text_output.config(state=tk.DISABLED)
					 # Summarize the text and display it separately
                summarized_text = text_summarizer(text)
                tab6_display_text.config(state=tk.NORMAL)
                tab6_display_text.insert(tk.END, summarized_text + '\n')
                tab6_display_text.config(state=tk.DISABLED)
        except KeyboardInterrupt:
            pass
        except sr.UnknownValueError:
            pass
        except sr.RequestError as e:
            text_output.config(state=tk.NORMAL)
            text_output.insert(tk.END, f"Error: {e}\n")
            text_output.config(state=tk.DISABLED)
# Audio File Processing Tab
def open_audio_file():
    audio_file_path = tkinter.filedialog.askopenfilename(filetypes=(("Audio Files", "*.wav"), ("Audio Files mp3", "*.mp3"),("All files", "*.*")))
    if audio_file_path:
        try:
            recognizer = sr.Recognizer()
            with sr.AudioFile(audio_file_path) as source:
                audio_data = recognizer.record(source)
                #audio_data.export("output_audio.wav", format="wav")
                text = recognizer.recognize_google(audio_data)
                audio_text_output.config(state=tk.NORMAL)
                audio_text_output.delete('1.0', tk.END)
                audio_text_output.insert(tk.END, text)
                audio_text_output.config(state=tk.DISABLED)
                # Summarize the text and display it separately
                summarized_text = "summary : " + text_summarizer(text)
                result1 = '\nSummary:{}'.format(summarized_text)
					 #audio_summary_output.config(state=tk.NORMAL)
                audio_summary_output.delete('1.0', tk.END)
                audio_summary_output.insert(tk.END, result1)
                audio_summary_output.config(state=tk.DISABLED)
        except sr.UnknownValueError:
            audio_text_output.config(state=tk.NORMAL)
            audio_text_output.delete('1.0', tk.END)
            audio_text_output.insert(tk.END, "Speech recognition could not understand audio.\n")
            audio_text_output.config(state=tk.DISABLED)
        except sr.RequestError as e:
            audio_text_output.config(state=tk.NORMAL)
            audio_text_output.delete('1.0', tk.END)
            audio_text_output.insert(tk.END, f"Error: {e}\n")
            audio_text_output.config(state=tk.DISABLED)

#main home tab
l1=Label(tab1,text='Enter text to summarize ',padx=5,pady=5)
l1.grid(column=0,row=1)
entry=ScrolledText(tab1,height=10)
entry.grid(column=0,row=2,columnspan=2,padx=5,pady=5)
#buttons
button1=Button(tab1,text='Reset',command=clear_text,width=12,bg='blue',fg='#fff')
button1.grid(column=0,row=4,padx=10,pady=10)
button1=Button(tab1,text='Summarize',command=get_summary,width=12,bg='#919598',fg='#000')
button1.grid(column=1,row=4,padx=10,pady=10)
button1=Button(tab1,text='Clear Result',command=clear_display_result,width=12,bg='#919598',fg='#000')
button1.grid(column=0,row=5,padx=10,pady=10)
button1=Button(tab1,text='Save',command=save_summary,width=12,bg='blue',fg='#fff')
button1.grid(column=1,row=5,padx=10,pady=10)
#display screen for result
tab1_display=ScrolledText(tab1,height=10)
tab1_display.grid(column=0,row=7,columnspan=3,padx=5,pady=5)
#file processing tab
l1=Label(tab2,text='Open file to summarize',padx=5,pady=5)
l1.grid(column=1,row=1)
displayed_file=ScrolledText(tab2,height=7)
displayed_file.grid(row=2,column=0, columnspan=3,padx=5,pady=3)
# BUTTONS FOR SECOND TAB/FILE READING TAB
b0=Button(tab2,text="Open File", width=12,command=openfiles,bg='#c5cae9')
b0.grid(row=3,column=0,padx=10,pady=10)

b1=Button(tab2,text="Reset ", width=12,command=clear_text_file,bg="#b9f6ca")
b1.grid(row=3,column=1,padx=10,pady=10)

b2=Button(tab2,text="Summarize", width=12,command=get_file_summary,bg='blue',fg='#fff')
b2.grid(row=3,column=2,padx=10,pady=10)

b3=Button(tab2,text="Clear Result", width=12,command=clear_text_result)
b3.grid(row=5,column=1,padx=10,pady=10)

b4=Button(tab2,text="Close", width=12,command=window.destroy)
b4.grid(row=5,column=2,padx=10,pady=10)

# Display Screen
# tab2_display_text = Text(tab2)
tab2_display_text = ScrolledText(tab2,height=10)
tab2_display_text.grid(row=7,column=0, columnspan=3,padx=5,pady=5)

# Allows you to edit
tab2_display_text.config(state=NORMAL)
# URL TAB
l1=Label(tab3,text="Enter URL To Summarize")
l1.grid(row=1,column=0)

raw_entry=StringVar()
url_entry=Entry(tab3,textvariable=raw_entry,width=50)
url_entry.grid(row=1,column=1)

# BUTTONS
button1=Button(tab3,text="Reset",command=clear_url_entry, width=12,bg='#03A9F4',fg='#fff')
button1.grid(row=4,column=0,padx=10,pady=10)

button2=Button(tab3,text="Get Text",command=get_text, width=12,bg='#03A9F4',fg='#fff')
button2.grid(row=4,column=1,padx=10,pady=10)

button3=Button(tab3,text="Clear Result", command=clear_url_display,width=12,bg='#03A9F4',fg='#fff')
button3.grid(row=5,column=0,padx=10,pady=10)

button4=Button(tab3,text="Summarize",command=get_url_summary, width=12,bg='#03A9F4',fg='#fff')
button4.grid(row=5,column=1,padx=10,pady=10)

# Display Screen For Result
url_display = ScrolledText(tab3,height=10)
url_display.grid(row=7,column=0, columnspan=3,padx=5,pady=5)


tab3_display_text = ScrolledText(tab3,height=10)
tab3_display_text.grid(row=10,column=0, columnspan=3,padx=5,pady=5)
# COMPARER TAB
l1=Label(tab4,text="Enter Text To Summarize")
l1.grid(row=1,column=0)

entry1=ScrolledText(tab4,height=10)
entry1.grid(row=2,column=0,columnspan=3,padx=5,pady=3)

# BUTTONS
button1=Button(tab4,text="Reset",command=clear_compare_text, width=12,bg='#03A9F4',fg='#fff')
button1.grid(row=4,column=0,padx=10,pady=10)

button2=Button(tab4,text="SpaCy",command=use_spacy, width=12,bg='red',fg='#fff')
button2.grid(row=4,column=1,padx=10,pady=10)

button3=Button(tab4,text="Clear Result", command=clear_compare_display_result,width=12,bg='#03A9F4',fg='#fff')
button3.grid(row=5,column=0,padx=10,pady=10)

button4=Button(tab4,text="NLTK",command=use_nltk, width=12,bg='#03A9F4',fg='#fff')
button4.grid(row=4,column=2,padx=10,pady=10)

button4=Button(tab4,text="Gensim",command=use_gensim, width=12,bg='#03A9F4',fg='#fff')
button4.grid(row=5,column=1,padx=10,pady=10)

button4=Button(tab4,text="Sumy",command=use_sumy, width=12,bg='#03A9F4',fg='#fff')
button4.grid(row=5,column=2,padx=10,pady=10)


variable = StringVar()
variable.set("SpaCy")
choice_button = OptionMenu(tab4,variable,"SpaCy","Gensim","Sumy","NLTK")
choice_button.grid(row=6,column=1)


# Display Screen For Result
tab4_display = ScrolledText(tab4,height=15)
tab4_display.grid(row=7,column=0, columnspan=3,padx=5,pady=5)
# Speech to Text Tab
l1 = Label(tab6, text='Speech to Text', padx=5, pady=5)
l1.grid(column=0, row=0)

start_button = Button(tab6, text='Start Listening', command=start_listening, width=20, bg='#03A9F4', fg='#fff')
start_button.grid(column=0, row=1, padx=10, pady=10)

text_output = ScrolledText(tab6, height=10, state=tk.DISABLED)
text_output.grid(column=0, row=2, padx=5, pady=5)

# Display Screen For Summarized Text
tab6_display_text = ScrolledText(tab6, height=10, state=tk.DISABLED)
tab6_display_text.grid(column=0, row=3, padx=5, pady=5)
# Audio File Processing Tab
l1 = Label(tab7, text='Audio File Processing', padx=5, pady=5)
l1.grid(column=0, row=0)

open_file_button = Button(tab7, text='Open Audio File', command=open_audio_file, width=20, bg='#03A9F4', fg='#fff')
open_file_button.grid(column=0, row=1, padx=10, pady=10)

audio_text_output = ScrolledText(tab7, height=10, state=tk.DISABLED)
audio_text_output.grid(column=0, row=2, padx=5, pady=5)

# Display Screen For Summarized Text
audio_summary_output = ScrolledText(tab7, height=10, state=tk.DISABLED)
audio_summary_output.grid(column=0, row=3, padx=5, pady=5)
#labels
label1=Label(tab1,text='Summarizer',padx=5,pady=5)
label1.grid(column=0,row=0)
label2=Label(tab2,text='File processing',padx=5,pady=5)
label2.grid(column=0,row=0)
label3=Label(tab3,text='URL',padx=5,pady=5)
label3.grid(column=0,row=0)
label4=Label(tab4,text='Comparer',padx=5,pady=5)
label4.grid(column=0,row=0)
label5=Label(tab5,text='About',padx=5,pady=5)
label5.grid(column=0,row=0)
# About TAB
about_label = Label(tab5,text="Summaryzer GUI  \n  @Vedant Sonawane",pady=5,padx=5)
about_label.grid(column=0,row=1)
window.mainloop()
window.mainloop()
