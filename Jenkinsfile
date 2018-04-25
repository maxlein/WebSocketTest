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
        sh ' cd build && tests/testfoo --gtest_output="xml:testresults.xml" && mkdir reports && mv testresults.xml reports/ '
        echo 'ls: $(ls)'
      }
    }
    stage('Artifact') {
      steps {
        archiveArtifacts(onlyIfSuccessful: true, artifacts: 'build/bin/*, bin/*')
      }
    }
  }
  post {
    always {
      junit 'build/reports/*.xml'

    }

  }
  options {
    timeout(time: 1, unit: 'HOURS')
  }
}