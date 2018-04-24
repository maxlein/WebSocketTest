pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        sh 'mkdir build && cd build && cmake .. && make'
      }
    }
    stage('Test') {
      steps {
        sh ' tests/testfoo --gtest_output="xml:testresults.xml" && mkdir reports && mv testresults.xml reports/ '
      }
    }
  }
}