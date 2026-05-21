docker run -d \
  --name oracle-uni \
  -p 1521:1521 \
  -e ORACLE_PWD=YourPassword123 \
  -v oracle-data:/opt/oracle/oradata \
  container-registry.oracle.com/database/free:latest
