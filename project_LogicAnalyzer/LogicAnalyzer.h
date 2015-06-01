class LogicAnalyzer {
   unsigned char *ptr;
   int triggerMode;

    public:
       LogicAnalyzer(unsigned char *);
       void setScanRate(unsigned int);
       void setTrigger(int);
       void start(void);
       void stop(void);
       void DMAInit(void); 
};
