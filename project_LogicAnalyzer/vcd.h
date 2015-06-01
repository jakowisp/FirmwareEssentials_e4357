
class vcd {
   unsigned char *ptr;
   unsigned int len;

   public:
   vcd(unsigned char *ptr,unsigned int length); 
   void generateDumpvars();
   private:
   void printbinary(unsigned char inputValue);
   void printVCDHeader(void);

};
 

